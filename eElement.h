#pragma once

#include <set>

#include "CoreDefines.h"

NS_CORE_START

enum class eElement
{
	SUN_GEAR = 'S',
	EPY_GEAR = 'E',
	CARRIER = 'C',
};


const std::set<eElement> c_centraleElements = { eElement::SUN_GEAR, eElement::EPY_GEAR, eElement::CARRIER };

inline char eElementToChar( const eElement& e )
{
	return char( e );
}

inline eElement charToeElement( const char c )
{
	return eElement( c );
}

NS_END