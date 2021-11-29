#ifndef AIRLY_INCLUDE_AIRLY_PROPERTIES_TEMPERATURE_H_
#define AIRLY_INCLUDE_AIRLY_PROPERTIES_TEMPERATURE_H_

/* Config for WebThings framework */
#include <WebThingConfig.h>

/* WebThings framework */
#include <Thing.h>

void describeTemperatureProperty(ThingDevice* device);
void setTemperatureProperty(const float temperature);

#endif  // AIRLY_INCLUDE_AIRLY_PROPERTIES_TEMPERATURE_H_
