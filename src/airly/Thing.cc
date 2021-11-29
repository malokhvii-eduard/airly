#include <airly/Thing.h>

/* Config for WebThings framework */
#include <WebThingConfig.h>

/* Arduino */
#include <Arduino.h>
#include <ESP8266WiFi.h>

/* WebThings framework */
#include <WebThingAdapter.h>

/* Scheduler */
#include <arduino-timer.h>

/* Compilation-time config */
#include <airly/Config.h>

/* Device */
#include <airly/Device.h>

// -------------------------------------------------------------------------- //
// Bosch Sensortec BME280
// -------------------------------------------------------------------------- //
#if defined(THING_HAS_BME280)

/* Library */
#include <Bme280.h>

/* Properties */
#include <airly/properties/BarometricPressure.h>
#include <airly/properties/Humidity.h>
#include <airly/properties/Temperature.h>

#if defined(THING_HAS_BME280) && !defined(BME280_ADDRESS)
#define BME280_ADDRESS Bme280TwoWireAddress::Primary
#endif

#if !defined(SCHEDULER_INTERVAL_POLL_BME280)
#define SCHEDULER_INTERVAL_POLL_BME280 10000
#endif

static Bme280TwoWire bme280;

static void beginBme280() {
  Wire.begin(THING_I2C_SDA, THING_I2C_SCL);

  bme280.begin(BME280_ADDRESS);
  bme280.setSettings(Bme280Settings::indoor());

  delay(1000);
}

static bool pollBme280(void *) {
  auto temperature = bme280.getTemperature();
  auto humidity = bme280.getHumidity();
  auto barometricPressure = bme280.getPressure();

  setTemperatureProperty(temperature);
  setHumidityProperty(humidity);
  setBarometricPressureProperty(barometricPressure);

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
#define SCHEDULER_INTERVAL_UPDATE_PROPERTIES 1000
#endif

static WebThingAdapter *adapter = nullptr;

static bool updateProperties(void *) {
  updateUptimeProperty();

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
}
// -------------------------------------------------------------------------- //

// -------------------------------------------------------------------------- //
// Thing
// -------------------------------------------------------------------------- //
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

static void beginWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.persistent(true);
  WiFi.setAutoReconnect(true);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void beginThing() {
  beginWiFi();

  auto thingHostname = getThingHostname();
  auto thingIdentity = getThingIdentity();

  WiFi.hostname(thingHostname);

  adapter = new WebThingAdapter(thingIdentity, WiFi.localIP());
  describeDevice(adapter);
  adapter->begin();

#if defined(THING_HAS_BME280)
  beginBme280();
#endif

  beginScheduler();
}

void updateThing() { scheduler.tick(); }
// -------------------------------------------------------------------------- //
