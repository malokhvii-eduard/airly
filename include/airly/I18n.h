#ifndef AIRLY_INCLUDE_AIRLY_I18N_H_
#define AIRLY_INCLUDE_AIRLY_I18N_H_

/* Compilation-time config */
#include <airly/Config.h>

#if !defined(LANG_EN_US) && !defined(LANG_RU_RU) && !defined(LANG_UK_UA)
#define LANG_UNDEFINED
#error \
    "Undefined language! Please define language via macro LANG_##_## \
(Example: LANG_EN_US). Available languages: en-US, ru-RU, uk-UA."
#else
#define LANG_DEFINED
#endif

namespace i18n {

extern const char* DeviceTitle;

#if defined(THING_HAS_TEMPERATURE_PROPERTY)
extern const char* TemperaturePropertyDescription;
extern const char* TemperaturePropertyTitle;
#endif

#if defined(THING_HAS_HUMIDITY_PROPERTY)
extern const char* HumidityPropertyDescription;
extern const char* HumidityPropertyTitle;
#endif

#if defined(THING_HAS_BAROMETRIC_PRESSURE_PROPERTY)
extern const char* BarometricPressurePropertyDescription;
extern const char* BarometricPressurePropertyTitle;
#endif

#if defined(THING_HAS_DEW_POINT_PROPERTY)
extern const char* DewPointPropertyDescription;
extern const char* DewPointPropertyTitle;
#endif

#if defined(THING_HAS_CARBON_DIOXIDE_PROPERTY)
extern const char* CarbonDioxidePropertyDescription;
extern const char* CarbonDioxidePropertyTitle;
#endif

}  // namespace i18n

#endif  // AIRLY_INCLUDE_AIRLY_I18N_H_
