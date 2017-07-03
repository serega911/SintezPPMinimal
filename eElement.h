#pragma once

#include "CoreDefines.h"

NS_CORE_START

enum class eElement
{
	SUN_GEAR = 'S',
	EPY_GEAR = 'E',
	SAT_GEAR = 's',
	CARRIER = 'C',
};


const eElement centraleElements[] = { eElement::SUN_GEAR, eElement::EPY_GEAR, eElement::CARRIER };
const int centraleElementsCount = sizeof( centraleElements ) / sizeof( eElement );
const eElement alleElements[] = { eElement::SUN_GEAR, eElement::EPY_GEAR, eElement::CARRIER, eElement::SAT_GEAR };
const int alleElementsCount = sizeof( alleElements ) / sizeof( eElement );

#define CENTRAL_E_ELEMENT_LOOP for (const auto&element: centraleElements)
#define ALL_E_ELEMENT_LOOP for (const auto&eelement: alleElements)

inline char eElementToChar( const eElement& e )
{
	return char( e );
}

inline eElement charToeElement( const char c )
{
	return eElement( c );
}

NS_END