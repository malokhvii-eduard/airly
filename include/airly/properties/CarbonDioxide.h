#ifndef AIRLY_INCLUDE_AIRLY_PROPERTIES_CARBON_DIOXIDE_H_
#define AIRLY_INCLUDE_AIRLY_PROPERTIES_CARBON_DIOXIDE_H_

/* Config for WebThings framework */
#include <WebThingConfig.h>

/* WebThings framework */
#include <Thing.h>

#if defined(THING_HAS_CARBON_DIOXIDE_PROPERTY)
void describeCarbonDioxideProperty(ThingDevice* device);
void setCarbonDioxideProperty(const unsigned short carbonDioxide);
#endif

#endif  // AIRLY_INCLUDE_AIRLY_PROPERTIES_CARBON_DIOXIDE_H_
