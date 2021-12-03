#include <airly/I18n.h>

/* AVR low-level */
#include <avr/pgmspace.h>

// -------------------------------------------------------------------------- //
// Translations: ru-RU, Russian, Russia
// -------------------------------------------------------------------------- //
#if defined(LANG_RU_RU)

namespace i18n {

#if defined(THING_HAS_TEMPERATURE_PROPERTY)
const char* TemperaturePropertyDescription PROGMEM =
    "Физическая величина, выражающая тепло и холод";
const char* TemperaturePropertyTitle PROGMEM = "Температура";
#endif

#if defined(THING_HAS_HUMIDITY_PROPERTY)
const char* HumidityPropertyDescription PROGMEM =
    "Концентрация водяного пара в воздухе";
const char* HumidityPropertyTitle PROGMEM = "Влажность";
#endif

#if defined(THING_HAS_BAROMETRIC_PRESSURE_PROPERTY)
const char* BarometricPressurePropertyDescription PROGMEM =
    "Давление в атмосфере Земли";
const char* BarometricPressurePropertyTitle PROGMEM = "Атмосферное давление";
#endif

#if defined(THING_HAS_DEW_POINT_PROPERTY)
const char* DewPointPropertyDescription PROGMEM =
    "Температура, при которой водяной пар начинает конденсироваться в воду";
const char* DewPointPropertyTitle PROGMEM = "Точка росы";
#endif

#if defined(THING_HAS_CARBON_DIOXIDE_PROPERTY)
const char* CarbonDioxidePropertyDescription PROGMEM =
    "Концентрация углекислого газа";
const char* CarbonDioxidePropertyTitle PROGMEM = "Углекислый газ";
#endif

}  // namespace i18n

#endif
// -------------------------------------------------------------------------- //
