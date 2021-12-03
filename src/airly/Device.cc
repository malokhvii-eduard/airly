#include <airly/Device.h>

/* Preprocessor-based localization */
#include <airly/I18n.h>

/* Properties */
#include <airly/properties/BarometricPressure.h>
#include <airly/properties/CarbonDioxide.h>
#include <airly/properties/DewPoint.h>
#include <airly/properties/Humidity.h>
#include <airly/properties/Temperature.h>

#if defined(THING_HAS_TEMPERATURE_PROPERTY)
#define TEMPERATURE_SENSOR_CAPABILITY "TemperatureSensor",
#else
#define TEMPERATURE_SENSOR_CAPABILITY
#endif

#if defined(THING_HAS_HUMIDITY_PROPERTY)
#define HUMIDITY_SENSOR_CAPABILITY "HumiditySensor",
#else
#define HUMIDITY_SENSOR_CAPABILITY
#endif

#if defined(THING_HAS_BAROMETRIC_PRESSURE_PROPERTY)
#define BAROMETRIC_PRESSURE_SENSOR_CAPABILITY "BarometricPressureSensor",
#else
#define BAROMETRIC_PRESSURE_SENSOR_CAPABILITY
#endif

#if defined(THING_HAS_CARBON_DIOXIDE_PROPERTY)
#define AIR_QUALITY_SENSOR_CAPABILITY "AirQualitySensor",
#else
#define AIR_QUALITY_SENSOR_CAPABILITY
#endif

static const char* deviceCapabilities[] = {
    TEMPERATURE_SENSOR_CAPABILITY HUMIDITY_SENSOR_CAPABILITY
        BAROMETRIC_PRESSURE_SENSOR_CAPABILITY
            AIR_QUALITY_SENSOR_CAPABILITY nullptr};
static ThingDevice device("0", i18n::DeviceTitle, deviceCapabilities);

void describeDevice(WebThingAdapter* adapter) {
#if defined(THING_HAS_TEMPERATURE_PROPERTY)
  describeTemperatureProperty(&device);
#endif

#if defined(THING_HAS_HUMIDITY_PROPERTY)
  describeHumidityProperty(&device);
#endif

#if defined(THING_HAS_BAROMETRIC_PRESSURE_PROPERTY)
  describeBarometricPressureProperty(&device);
#endif

#if defined(THING_HAS_DEW_POINT_PROPERTY)
  describeDewPointProperty(&device);
#endif

#if defined(THING_HAS_CARBON_DIOXIDE_PROPERTY)
  describeCarbonDioxideProperty(&device);
#endif

  adapter->addDevice(&device);
}
