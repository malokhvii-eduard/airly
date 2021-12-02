#ifndef AIRLY_INCLUDE_AIRLY_I18N_H_
#define AIRLY_INCLUDE_AIRLY_I18N_H_

/* Compilation-time config */
#include <airly/Config.h>

#if !defined(LANG_EN_US)
#define LANG_UNDEFINED
#error \
    "Undefined language! Please define language via macro LANG_##_## \
(Example: LANG_EN_US). Available languages: en-US."
#else
#define LANG_DEFINED
#endif

namespace i18n {

extern const char* DeviceTitle;
extern const char* UptimePropertyDescription;
extern const char* UptimePropertyTitle;

#if defined(THING_HAS_BME280)
extern const char* BarometricPressurePropertyDescription;
extern const char* BarometricPressurePropertyTitle;
extern const char* DewPointPropertyDescription;
extern const char* DewPointPropertyTitle;
extern const char* HumidityPropertyDescription;
extern const char* HumidityPropertyTitle;
extern const char* TemperaturePropertyDescription;
extern const char* TemperaturePropertyTitle;
#endif

#if defined(THING_HAS_MHZ19)
extern const char* CarbonDioxidePropertyDescription;
extern const char* CarbonDioxidePropertyTitle;
#endif

}  // namespace i18n

#endif  // AIRLY_INCLUDE_AIRLY_I18N_H_
