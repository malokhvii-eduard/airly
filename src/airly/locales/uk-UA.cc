#include <airly/I18n.h>

/* AVR low-level */
#include <avr/pgmspace.h>

// -------------------------------------------------------------------------- //
// Translations: uk-UA, Ukranian, Ukraine
// -------------------------------------------------------------------------- //
#if defined(LANG_UK_UA)

namespace i18n {

#if defined(THING_HAS_TEMPERATURE_PROPERTY)
const char* TemperaturePropertyDescription PROGMEM =
    "Фізична величина, що виражає тепло та холод";
const char* TemperaturePropertyTitle PROGMEM = "Температура";
#endif

#if defined(THING_HAS_HUMIDITY_PROPERTY)
const char* HumidityPropertyDescription PROGMEM =
    "Концентрація водяної пари у повітрі";
const char* HumidityPropertyTitle PROGMEM = "Вологість";
#endif

#if defined(THING_HAS_BAROMETRIC_PRESSURE_PROPERTY)
const char* BarometricPressurePropertyDescription PROGMEM =
    "Тиск у атмосфері Землі";
const char* BarometricPressurePropertyTitle PROGMEM = "Атмосферний тиск";
#endif

#if defined(THING_HAS_DEW_POINT_PROPERTY)
const char* DewPointPropertyDescription PROGMEM =
    "Температура, при якій водяна пара починає конденсуватися у воду";
const char* DewPointPropertyTitle PROGMEM = "Точка роси";
#endif

#if defined(THING_HAS_CARBON_DIOXIDE_PROPERTY)
const char* CarbonDioxidePropertyDescription PROGMEM =
    "Концентрація вуглекислого газу";
const char* CarbonDioxidePropertyTitle PROGMEM = "Вуглекислий газ";
#endif

}  // namespace i18n

#endif
// -------------------------------------------------------------------------- //
