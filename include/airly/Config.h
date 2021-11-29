#ifndef AIRLY_INCLUDE_AIRLY_CONFIG_H_
#define AIRLY_INCLUDE_AIRLY_CONFIG_H_

#if !defined(THING_MODEL_B) && !defined(THING_MODEL_M)
#error \
    "Undefined thing model! Please define thing model via macro THING_#####_# \
(Example: THING_MODEL_B). Supported thing models: Model B, Model M."
#define THING_UNDEFINED
#endif

#endif  // AIRLY_INCLUDE_AIRLY_CONFIG_H_
