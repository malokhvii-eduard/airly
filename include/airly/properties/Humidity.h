#ifndef AIRLY_INCLUDE_AIRLY_PROPERTIES_HUMIDITY_H_
#define AIRLY_INCLUDE_AIRLY_PROPERTIES_HUMIDITY_H_

/* Config for WebThings framework */
#include <WebThingConfig.h>

/* WebThings framework */
#include <Thing.h>

void describeHumidityProperty(ThingDevice* device);
void setHumidityProperty(const float humidity);

#endif  // AIRLY_INCLUDE_AIRLY_PROPERTIES_HUMIDITY_H_
