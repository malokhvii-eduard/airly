#include <airly/I18n.h>

/* AVR low-level */
#include <avr/pgmspace.h>

// -------------------------------------------------------------------------- //
// Translations: common
// -------------------------------------------------------------------------- //
#if defined(LANG_DEFINED)

namespace i18n {

#if defined(THING_MODEL_B)
const char* DeviceTitle PROGMEM = "Airly Model B";
#elif defined(THING_MODEL_M)
const char* DeviceTitle PROGMEM = "Airly Model M";
#endif

}  // namespace i18n

#endif
// -------------------------------------------------------------------------- //

// -------------------------------------------------------------------------- //
// Translations: en-US, English, United States
// -------------------------------------------------------------------------- //
#if defined(LANG_EN_US)

namespace i18n {

#if defined(THING_HAS_TEMPERATURE_PROPERTY)
const char* TemperaturePropertyDescription PROGMEM =
    "A physical quantity that expresses hot and cold";
const char* TemperaturePropertyTitle PROGMEM = "Temperature";
#endif

#if defined(THING_HAS_HUMIDITY_PROPERTY)
const char* HumidityPropertyDescription PROGMEM =
    "The concentration of water vapor present in the air";
const char* HumidityPropertyTitle PROGMEM = "Humidity";
#endif

#if defined(THING_HAS_BAROMETRIC_PRESSURE_PROPERTY)
const char* BarometricPressurePropertyDescription PROGMEM =
    "The pressure within the atmosphere of Earth";
const char* BarometricPressurePropertyTitle PROGMEM = "Barometric pressure";
#endif

#if defined(THING_HAS_DEW_POINT_PROPERTY)
const char* DewPointPropertyDescription PROGMEM =
    "The temperature at which water vapor begins to condense into water";
const char* DewPointPropertyTitle PROGMEM = "Dew point";
#endif

#if defined(THING_HAS_CARBON_DIOXIDE_PROPERTY)
const char* CarbonDioxidePropertyDescription PROGMEM =
    "The concentration of carbon dioxide";
const char* CarbonDioxidePropertyTitle PROGMEM = "Carbon dioxide";
#endif

}  // namespace i18n

#endif
// -------------------------------------------------------------------------- //
