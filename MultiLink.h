#pragma once

#include <set>

#include "CoreDefines.h"
#include "Element.h"
#include "IObject.h"
#include "ISchemeElement.h"

NS_CORE_START

SHARED_PTR( MultiLink, MultiLink_p )

class MultiLink : public IObject, ISchemeElement
{
private:

	typedef std::set<Element_p> ElementContainer;
	ElementContainer							m_elements;

	MultiLink();
	MultiLink( const MultiLink& ) = delete;

	

public:

	static MultiLink_p							create();
	MultiLink_p									clone() const;
	//virtual void								writeToFile( std::ostream& file ) const override;
	//virtual void								writeToConsole() const override;

	void										addElement( const Element_p& element );
	bool										isContain( const Element_p& elem ) const;
	const ElementContainer&						getElements() const;

	bool										isIntersect( const MultiLink_p& multiLink ) const;
	
	friend MultiLink_p							operator+( const MultiLink_p& multiLink1, const MultiLink_p& multiLink2 ){
		MultiLink_p result = nullptr;

		if ( multiLink1->isIntersect( multiLink2 ) )
		{
			result = MultiLink::create();
			result->m_elements.insert( multiLink1->m_elements.cbegin(), multiLink1->m_elements.cend() );
			result->m_elements.insert( multiLink2->m_elements.cbegin(), multiLink2->m_elements.cend() );
		}

		return result;
	}

	friend MultiLink_p							operator+=(const MultiLink_p& multiLink1, const MultiLink_p& multiLink2){
		multiLink1->m_elements.insert(multiLink2->m_elements.cbegin(), multiLink2->m_elements.cend());
		return multiLink1;
	}

	friend bool									operator==( const MultiLink& multiLink1, const MultiLink& multiLink2 )
	{
		return multiLink1.m_elements == multiLink2.m_elements;
	}

};

NS_END