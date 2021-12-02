#include <airly/Thing.h>

/* Config for WebThings framework */
#include <WebThingConfig.h>

/* Arduino */
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>

/* WebThings framework */
#include <WebThingAdapter.h>

/* Scheduler */
#include <arduino-timer.h>

/* Compilation-time config */
#include <airly/Config.h>

/* Device */
#include <airly/Device.h>

// -------------------------------------------------------------------------- //
// Utilities
// -------------------------------------------------------------------------- //

static void onBuiltinLed() { digitalWrite(LED_BUILTIN, LOW); }

static void offBuiltinLed() { digitalWrite(LED_BUILTIN, HIGH); }

static String getThingHostname() {
  auto macAddress = WiFi.macAddress();
  macAddress.replace(":", "");

  auto identity = String("airly-");
  identity += macAddress;
  identity.toLowerCase();
  return identity;
}

static String getThingIdentity() {
  auto macAddress = WiFi.macAddress();
  macAddress.replace(":", "");
  macAddress.toLowerCase();
  return macAddress;
}

// -------------------------------------------------------------------------- //

// -------------------------------------------------------------------------- //
// Bosch Sensortec BME280
// -------------------------------------------------------------------------- //
#if defined(THING_HAS_BME280)

/* Library */
#include <Bme280.h>

/* Properties */
#include <airly/properties/BarometricPressure.h>
#include <airly/properties/DewPoint.h>
#include <airly/properties/Humidity.h>
#include <airly/properties/Temperature.h>

#if defined(THING_HAS_BME280) && !defined(BME280_ADDRESS)
#define BME280_ADDRESS Bme280TwoWireAddress::Primary
#endif

#if !defined(SCHEDULER_INTERVAL_POLL_BME280)
#define SCHEDULER_INTERVAL_POLL_BME280 10000  // 10 seconds
#endif

static Bme280TwoWire bme280;

static void beginBme280() {
  bme280.begin(BME280_ADDRESS);
  bme280.setSettings(Bme280Settings::indoor());

  delay(1000);  // 1 second
}

static float calculateDewPoint(const float temperature, const float humidity) {
  auto t = round(temperature);
  auto h = round(humidity);
  if (t < -45 || t > 65 || h == 0) {
    return NAN;
  }

  float a = 17.62;
  float b = 243.12;

  /**
   * Magnus-Tetens formula (Sonntag90):
   *
   * Ts = (bα(T,RH)) / (a - α(T,RH))
   *
   * Ts is the dew point;
   * T is the temperature;
   * RH is the relative humidity of the air;
   * a and b are coefficients. For Sonntag90 constant set, a = 17.62
   * and b = 243.12°C;
   * α(T,RH) = ln(RH/100) + aT/(b+T)
   */
  float alpha = log(humidity / 100) + a * temperature / (b + temperature);
  float dewPoint = (b * alpha) / (a - alpha);

  return dewPoint;
}

static bool pollBme280(void *) {
  auto temperature = bme280.getTemperature();
  auto humidity = bme280.getHumidity();
  auto barometricPressure = bme280.getPressure();
  auto dewPoint = calculateDewPoint(temperature, humidity);

  setTemperatureProperty(temperature);
  setHumidityProperty(humidity);
  setBarometricPressureProperty(barometricPressure);

  if (!isnan(dewPoint)) {
    setDewPointProperty(dewPoint);
  }

  return true;
}

#endif
// -------------------------------------------------------------------------- //

// -------------------------------------------------------------------------- //
// Winsen MH-Z19
// -------------------------------------------------------------------------- //
#if defined(THING_HAS_MHZ19)
/* Library */
#include <Mhz19.h>

/* Properties */
#include <airly/properties/CarbonDioxide.h>

#if !defined(SCHEDULER_INTERVAL_POLL_MHZ19)
#define SCHEDULER_INTERVAL_POLL_MHZ19 30000  // 30 seconds
#endif

#define MHZ19_UART_BAUDRATE 9600  // kbps

static SoftwareSerial mhz19Serial(MHZ19_UART_RX, MHZ19_UART_TX);
static Mhz19 mhz19;
static bool isMhz19PreheatingDone = false;

static void beginMhz19() {
  mhz19Serial.begin(MHZ19_UART_BAUDRATE);

  mhz19.begin(&mhz19Serial);
  mhz19.setMeasuringRange(Mhz19MeasuringRange::Ppm_5000);

#if !defined(MHZ19_DISABLE_AUTO_BASE_CALIBRATION)
  mhz19.enableAutoBaseCalibration();
#else
  mhz19.disableAutoBaseCalibration();
#endif

  delay(1000);  // 1 second
}

static bool pollMhz19(void *) {
  if (isMhz19PreheatingDone) {
    auto carbonDioxide = mhz19.getCarbonDioxide();
    if (carbonDioxide < 0) carbonDioxide = 0;

    setCarbonDioxideProperty(carbonDioxide);
  }

  return true;
}

#endif
// -------------------------------------------------------------------------- //

// -------------------------------------------------------------------------- //
// Adapter, common properties
// -------------------------------------------------------------------------- //
/* Properties */
#include <airly/properties/Uptime.h>

#if !defined(SCHEDULER_INTERVAL_UPDATE_PROPERTIES)
#define SCHEDULER_INTERVAL_UPDATE_PROPERTIES 1000  // 1 second
#endif

static WebThingAdapter *adapter = nullptr;

static bool updateProperties(void *) {
  updateUptimeProperty();

#if defined(THING_HAS_MHZ19)
  if (!isMhz19PreheatingDone) {
    if (mhz19.isReady()) {
      isMhz19PreheatingDone = true;
      offBuiltinLed();
    }
  }
#endif

  if (WiFi.status() == WL_CONNECTED) {
    adapter->update();
  }

  return true;
}
// -------------------------------------------------------------------------- //

// -------------------------------------------------------------------------- //
// Tasks scheduler
// -------------------------------------------------------------------------- //
#if defined(THING_MODEL_B)
#define SCHEDULER_TASKS 2
#elif defined(THING_MODEL_M)
#define SCHEDULER_TASKS 3
#else
#define SCHEDULER_TASKS 1
#endif

static Timer<SCHEDULER_TASKS> scheduler;

static void beginScheduler() {
  scheduler.every(SCHEDULER_INTERVAL_UPDATE_PROPERTIES, updateProperties);

#if defined(THING_HAS_BME280)
  scheduler.every(SCHEDULER_INTERVAL_POLL_BME280, pollBme280);
#endif

#if defined(THING_HAS_MHZ19)
  scheduler.every(SCHEDULER_INTERVAL_POLL_MHZ19, pollMhz19);
#endif
}
// -------------------------------------------------------------------------- //

// -------------------------------------------------------------------------- //
// Thing
// -------------------------------------------------------------------------- //
#if !defined(UART_BAUDRATE)
#define UART_BAUDRATE 9600  // kbps
#endif

static void beginBuiltinLed() { pinMode(LED_BUILTIN, OUTPUT); }

static void beginWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.persistent(true);
  WiFi.setAutoReconnect(true);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    // TODO: Add captive portal
    delay(500);  // 500 milliseconds
  }
}

static void beginSerial() {
  Serial.begin(UART_BAUDRATE);
  Serial.println();
}

static void beginTwoWire() { Wire.begin(I2C_SDA, I2C_SCL); }

void beginThing() {
  beginBuiltinLed();
  onBuiltinLed();

  auto thingHostname = getThingHostname();
  auto thingIdentity = getThingIdentity();
  WiFi.hostname(thingHostname);
  beginWiFi();

  adapter = new WebThingAdapter(thingIdentity, WiFi.localIP());
  describeDevice(adapter);
  adapter->begin();

  beginSerial();  // Skip debug messages from WebThings framework

#if defined(THING_HAS_BME280)
  beginTwoWire();
  beginBme280();
#endif

#if defined(THING_HAS_MHZ19)
  beginMhz19();
#endif

  beginScheduler();

#if !defined(THING_HAS_MHZ19)
  offBuiltinLed();
#endif
}

void updateThing() { scheduler.tick(); }
// --------------------------------------------------------------------------
// //