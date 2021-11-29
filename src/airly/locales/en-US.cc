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

const char* UptimePropertyTitle PROGMEM = "Uptime";
const char* UptimePropertyDescription PROGMEM =
    "The time during which the thing is in operation";

}  // namespace i18n

#endif
// -------------------------------------------------------------------------- //
