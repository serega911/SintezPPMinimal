#pragma once

#include <fstream>
#include <memory>

#include "CoreDefines.h"

NS_CORE_START

SHARED_PTR(IObject, IObject_p)

class IObject
{
public:
	//virtual void writeToFile( std::ostream& file ) const = 0;
	//virtual void writeToConsole() const = 0;
};

NS_END