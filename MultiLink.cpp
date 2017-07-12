#include "MultiLink.h"
NS_CORE_USING


MultiLink::MultiLink()
{
}

MultiLink_p MultiLink::create()
{
	return MultiLink_p( new MultiLink );
}

MultiLink_p MultiLink::clone() const
{
	MultiLink_p clone = create();
	clone->m_elements = m_elements;
	return clone;
}

const MultiLink::ElementContainer& MultiLink::getElements() const
{
	return m_elements;
}

bool MultiLink::isContain( const Element_p& elem ) const
{
	return m_elements.find( elem ) != m_elements.end();
}

void MultiLink::addElement( const Element_p& element )
{
	m_elements.insert( element );
}

// void MultiLink::writeToConsole() const
// {
// 	for ( const auto& it : m_elements )
// 	{
// 		it->writeToConsole();
// 	}
// }

// void MultiLink::writeToFile( std::ostream& file ) const
// {
// 	for ( const auto& it : m_elements )
// 	{
// 		it->writeToFile( file );
// 	}
// }

bool MultiLink::isIntersect( const MultiLink_p& multiLink ) const
{
	bool result = false;

	for ( const auto& elem : m_elements )
	{
		if ( multiLink->isContain( elem ) )
		{
			result = true;
			break;
		}
	}

	return result;
}




