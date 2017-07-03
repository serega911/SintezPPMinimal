#pragma once

#include "CoreDefines.h"

NS_CORE_START

USER_DEFINED_TYPE_INTEGRAL( GearSetNumer, int );
USER_DEFINED_TYPE_INTEGRAL( FrictionNumer, int );
USER_DEFINED_TYPE_INTEGRAL( BrakeNumer, int );
USER_DEFINED_TYPE_INTEGRAL( GearNumer, int );

#define LOOP_UP(type, varName, begin, end) for (type varName(begin); varName <= type(end); varName++)
#define GEAR_SET_NUM_LOOP_UP(N) LOOP_UP (GearSetNumer, gearSetNumber, 1, N)

NS_END