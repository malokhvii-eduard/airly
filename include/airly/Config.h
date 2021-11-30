#ifndef AIRLY_INCLUDE_AIRLY_CONFIG_H_
#define AIRLY_INCLUDE_AIRLY_CONFIG_H_

#if !defined(THING_MODEL_B) && !defined(THING_MODEL_M)
#error \
    "Undefined thing model! Please define thing model via macro THING_#####_# \
(Example: THING_MODEL_B). Supported thing models: Model B, Model M."
#define THING_UNDEFINED
#endif

#if defined(THING_MODEL_B)
#define THING_HAS_BME280
#elif defined(THING_MODEL_M)
#define THING_HAS_BME280
#define THING_HAS_MHZ19
#endif

#if defined(THING_HAS_BME280)
#if !defined(I2C_SDA)
#define I2C_SDA D2
#endif

#if !defined(THING_I2C_SCL)
#define I2C_SCL D1
#endif
#endif

#if !defined(MHZ19_UART_RX)
#define MHZ19_UART_RX D5
#endif
#endif

#if defined(THING_HAS_MHZ19)
#if !defined(MHZ19_UART_TX)
#define MHZ19_UART_TX D6
#endif

#endif  // AIRLY_INCLUDE_AIRLY_CONFIG_H_
