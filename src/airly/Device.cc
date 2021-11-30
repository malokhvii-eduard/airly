#include <airly/Device.h>

/* Preprocessor-based localization */
#include <airly/I18n.h>

/* Common properties */
#include <airly/properties/Uptime.h>

#if defined(THING_HAS_BME280)
/* Properties for Bosch Sensortec BME280 */
#include <airly/properties/BarometricPressure.h>
#include <airly/properties/Humidity.h>
#include <airly/properties/Temperature.h>

#define BME280_CAPABILITIES \
  "TemperatureSensor", "HumiditySensor", "BarometricPressureSensor",
#else
#define BME280_CAPABILITIES
#endif

#if defined(THING_HAS_MHZ19)
/* Properties for Winsen MH-Z19 */
#include <airly/properties/CarbonDioxide.h>

#define MHZ19_CAPABILITIES "AirQualitySensor",
#else
#define MHZ19_CAPABILITIES
#endif

static const char* deviceCapabilities[] = {
    BME280_CAPABILITIES MHZ19_CAPABILITIES nullptr};
static ThingDevice device("0", i18n::DeviceTitle, deviceCapabilities);

void describeDevice(WebThingAdapter* adapter) {
#if defined(THING_HAS_BME280)
  describeTemperatureProperty(&device);
  describeHumidityProperty(&device);
  describeBarometricPressureProperty(&device);
#endif

#if defined(THING_HAS_MHZ19)
  describeCarbonDioxideProperty(&device);
#endif

  describeUptimeProperty(&device);

  adapter->addDevice(&device);
}
