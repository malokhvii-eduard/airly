#include <airly/I18n.h>

/* AVR low-level */
#include <avr/pgmspace.h>

// -------------------------------------------------------------------------- //
// Translations: common
// -------------------------------------------------------------------------- //
#if defined(LANG_DEFINED) && defined(THING_MODEL_B)

namespace i18n {

const char* DeviceTitle PROGMEM = "Airly Model B";

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
const char* HumidityPropertyDescription PROGMEM =
    "The concentration of water vapor present in the air";
const char* HumidityPropertyTitle PROGMEM = "Humidity";
const char* TemperaturePropertyDescription PROGMEM =
    "A physical quantity that expresses hot and cold";
const char* TemperaturePropertyTitle PROGMEM = "Temperature";
#endif

}  // namespace i18n

#endif
// -------------------------------------------------------------------------- //
