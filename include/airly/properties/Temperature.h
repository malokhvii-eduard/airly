#ifndef AIRLY_INCLUDE_AIRLY_PROPERTIES_TEMPERATURE_H_
#define AIRLY_INCLUDE_AIRLY_PROPERTIES_TEMPERATURE_H_

/* Config for WebThings framework */
#include <WebThingConfig.h>

/* WebThings framework */
#include <Thing.h>

#if defined(THING_HAS_TEMPERATURE_PROPERTY)
void describeTemperatureProperty(ThingDevice* device);
void setTemperatureProperty(const float temperature);
#endif

#endif  // AIRLY_INCLUDE_AIRLY_PROPERTIES_TEMPERATURE_H_
