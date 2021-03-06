#ifndef AIRLY_INCLUDE_AIRLY_PROPERTIES_DEW_POINT_H_
#define AIRLY_INCLUDE_AIRLY_PROPERTIES_DEW_POINT_H_

/* Config for WebThings framework */
#include <WebThingConfig.h>

/* WebThings framework */
#include <Thing.h>

#if defined(THING_HAS_DEW_POINT_PROPERTY)
void describeDewPointProperty(ThingDevice* device);
void setDewPointProperty(const float DewPoint);
float calculateDewPoint(const float temperature, const float humidity);
#endif

#endif  // AIRLY_INCLUDE_AIRLY_PROPERTIES_DEW_POINT_H_
