#include <airly/I18n.h>

/* AVR low-level */
#include <avr/pgmspace.h>

// -------------------------------------------------------------------------- //
// Translations: ru-RU, Russian, Russia
// -------------------------------------------------------------------------- //
#if defined(LANG_RU_RU)

namespace i18n {

const char* UptimePropertyDescription PROGMEM =
    "Время, в течение которого вещь находится в эксплуатации";
const char* UptimePropertyTitle PROGMEM = "Аптайм";

#if defined(THING_HAS_BME280)
const char* BarometricPressurePropertyDescription PROGMEM =
    "Давление в атмосфере Земли";
const char* BarometricPressurePropertyTitle PROGMEM = "Атмосферное давление";
const char* DewPointPropertyDescription PROGMEM =
    "Температура, при которой водяной пар начинает конденсироваться в воду";
const char* DewPointPropertyTitle PROGMEM = "Точка росы";
const char* HumidityPropertyDescription PROGMEM =
    "Концентрация водяного пара в воздухе";
const char* HumidityPropertyTitle PROGMEM = "Влажность";
const char* TemperaturePropertyDescription PROGMEM =
    "Физическая величина, выражающая тепло и холод";
const char* TemperaturePropertyTitle PROGMEM = "Температура";
#endif

#if defined(THING_HAS_MHZ19)
const char* CarbonDioxidePropertyDescription PROGMEM =
    "Концентрация углекислого газа";
const char* CarbonDioxidePropertyTitle PROGMEM = "Углекислый газ";
#endif

}  // namespace i18n

#endif
// -------------------------------------------------------------------------- //
