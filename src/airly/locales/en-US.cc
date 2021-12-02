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

const char* UptimePropertyDescription PROGMEM =
    "The time during which the thing is in operation";
const char* UptimePropertyTitle PROGMEM = "Uptime";

#if defined(THING_HAS_BME280)
const char* BarometricPressurePropertyDescription PROGMEM =
    "The pressure within the atmosphere of Earth";
const char* BarometricPressurePropertyTitle PROGMEM = "Barometric pressure";
const char* DewPointPropertyDescription PROGMEM =
    "The temperature at which water vapor begins to condense into water";
const char* DewPointPropertyTitle PROGMEM = "Dew point";
const char* HumidityPropertyDescription PROGMEM =
    "The concentration of water vapor present in the air";
const char* HumidityPropertyTitle PROGMEM = "Humidity";
const char* TemperaturePropertyDescription PROGMEM =
    "A physical quantity that expresses hot and cold";
const char* TemperaturePropertyTitle PROGMEM = "Temperature";
#endif

#if defined(THING_HAS_MHZ19)
const char* CarbonDioxidePropertyDescription PROGMEM =
    "Concentration of carbon dioxide";
const char* CarbonDioxidePropertyTitle PROGMEM = "Carbon dioxide";
#endif

}  // namespace i18n

#endif
// -------------------------------------------------------------------------- //
