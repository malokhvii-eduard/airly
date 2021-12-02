#include <airly/I18n.h>

/* AVR low-level */
#include <avr/pgmspace.h>

// -------------------------------------------------------------------------- //
// Translations: uk-UA, Ukranian, Ukraine
// -------------------------------------------------------------------------- //
#if defined(LANG_UK_UA)

namespace i18n {

const char* UptimePropertyDescription PROGMEM =
    "Час, протягом якого річ перебуває в експлуатації";
const char* UptimePropertyTitle PROGMEM = "Аптайм";

#if defined(THING_HAS_BME280)
const char* BarometricPressurePropertyDescription PROGMEM =
    "Тиск у атмосфері Землі";
const char* BarometricPressurePropertyTitle PROGMEM = "Атмосферний тиск";
const char* DewPointPropertyDescription PROGMEM =
    "Температура, при якій водяна пара починає конденсуватися у воду";
const char* DewPointPropertyTitle PROGMEM = "Точка роси";
const char* HumidityPropertyDescription PROGMEM =
    "Концентрація водяної пари у повітрі";
const char* HumidityPropertyTitle PROGMEM = "Вологість";
const char* TemperaturePropertyDescription PROGMEM =
    "Фізична величина, що виражає тепло та холод";
const char* TemperaturePropertyTitle PROGMEM = "Температура";
#endif

#if defined(THING_HAS_MHZ19)
const char* CarbonDioxidePropertyDescription PROGMEM =
    "Концентрація вуглекислого газу";
const char* CarbonDioxidePropertyTitle PROGMEM = "Вуглекислий газ";
#endif

}  // namespace i18n

#endif
// -------------------------------------------------------------------------- //
