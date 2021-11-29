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
extern const char* UptimePropertyTitle;
extern const char* UptimePropertyDescription;

}  // namespace i18n

#endif  // AIRLY_INCLUDE_AIRLY_I18N_H_
