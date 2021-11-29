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
