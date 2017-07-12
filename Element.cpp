#include <iostream>
#include <set>

#include "Element.h"

NS_CORE_USING

Element::Element( eElement type, GearSetNumer gearSetNumber )
: m_type(type), m_gearSet(gearSetNumber)
{
}

Element_p Element::create( eElement type, GearSetNumer gearSetNumber )
{
	static std::set<Element_p> elements;
	Element_p ret = nullptr;

	for ( const auto& it : elements )
	{
		if ( it->m_gearSet == gearSetNumber && it->m_type == type )
		{
			ret = it;
			break;
		}
	}

	if ( !ret )
	{
		ret = Element_p( new Element( type, gearSetNumber ) );
		elements.insert( ret );
	}

	return ret;
}
 
// void Element::writeToFile( std::ostream& file ) const
// {
// 	file << eElementToChar( m_type ) << m_gearSet.getValue();
// }

// void Element::writeToConsole() const
// {
// 	std::cout << eElementToChar( m_type ) << m_gearSet.getValue();
// }

const eElement& Element::getType() const
{
	return m_type;
}

const GearSetNumer& Element::getGearSetNumer() const
{
	return m_gearSet;
}


