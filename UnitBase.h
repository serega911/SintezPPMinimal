#pragma once

#include "CoreDefines.h"

NS_CORE_START

class UnitBase
{
public:

	virtual void								run() = 0;
	virtual bool								checkRequirements() const = 0;

};

NS_END