#include <vector>
#include <iostream>
#include <set>

#include "CoreTests.h"
#include "Types.h"

#include "eElement.h"
#include "Element.h"
#include "MultiLink.h"
#include "Permutation.h"
#include "Subset.h"
#include "OrderedSample.h"

NS_CORE_USING

static NS_CORE Element_p elem1 = NS_CORE Element::create( NS_CORE eElement::SUN_GEAR, NS_CORE GearSetNumer( 1 ) );
static NS_CORE Element_p elem2 = NS_CORE Element::create( NS_CORE eElement::EPY_GEAR, NS_CORE GearSetNumer( 1 ) );
static NS_CORE Element_p elem3 = NS_CORE Element::create( NS_CORE eElement::CARRIER, NS_CORE GearSetNumer( 1 ) );
static NS_CORE Element_p elem4 = NS_CORE Element::create( NS_CORE eElement::SAT_GEAR, NS_CORE GearSetNumer( 1 ) );

bool CoreTest::exec()
{
	return 
		eElementTest()
		&& elementTest()
		&& multiLinkTest()
		;
}

bool Core::CoreTest::eElementTest()
{
	bool result = true;

	struct Pair
	{
		eElement elem;
		char c;
	};
	std::vector<Pair> vect;
	vect.push_back( { eElement::SUN_GEAR, 'S' } );
	vect.push_back( { eElement::EPY_GEAR, 'E' } );
	vect.push_back( { eElement::CARRIER, 'C' } );
	vect.push_back( { eElement::SAT_GEAR, 's' } );
	for ( const auto& it : vect )
	{
		bool local = result && eElementToChar( it.elem ) == it.c && charToeElement( it.c ) == it.elem;
		if ( !local )
			std::cout << it.c << ": failed to convert" << std::endl;
	}

	return result;
}

bool Core::CoreTest::elementTest()
{
	bool result = true;

	const int gearSetsCount = 3;
	bool gearSetNumOk = true;
	bool eElementOk = true;
	std::set<NS_CORE Element_p> elements;
	for ( int i = 0; i < 2; i++ )
		GEAR_SET_NUM_LOOP_UP( gearSetsCount )
		{
			ALL_E_ELEMENT_LOOP
			{
				Element_p element = Element::create( eelement, gearSetNumber );
				elements.insert( element );
				gearSetNumOk = gearSetNumOk && gearSetNumber == element->getGearSetNumer();
				eElementOk = eElementOk && eelement == element->getType();
			}
		}
	bool local = elements.size() == gearSetsCount * alleElementsCount && gearSetNumOk && eElementOk;
	result = result && local;

	NS_CORE Element_p elem1 = NS_CORE Element::create( NS_CORE eElement::EPY_GEAR, NS_CORE GearSetNumer( 2 ) );
	NS_CORE Element_p elem2 = NS_CORE Element::create( NS_CORE eElement::EPY_GEAR, NS_CORE GearSetNumer( 2 ) );
	result = result && elem1 == elem2;

	return result;
}


bool Core::CoreTest::multiLinkTest()
{
	bool result = true;

	NS_CORE MultiLink_p multiLink = NS_CORE MultiLink::create();
	multiLink->addElement( elem1 );
	multiLink->addElement( elem2 );
	result = result && multiLink->isContain( elem1 ) == true;
	result = result && multiLink->isContain( elem2 ) == true;
	result = result && multiLink->isContain( elem3 ) == false;
	const auto& elements = multiLink->getElements();
	result = result && elements.size() == 2;

	NS_CORE MultiLink_p multiLink1 = NS_CORE MultiLink::create();
	NS_CORE MultiLink_p multiLink2 = NS_CORE MultiLink::create();

	multiLink1->addElement( elem1 );
	multiLink1->addElement( elem2 );
	multiLink2->addElement( elem3 );
	multiLink2->addElement( elem4 );
	bool local1 = multiLink1->isIntersect( multiLink2 ) == false;
	NS_CORE MultiLink_p multiLink3 = multiLink1 + multiLink2;
	bool local2 = multiLink3 == nullptr;
	multiLink1->addElement( elem3 );
	NS_CORE MultiLink_p multiLink4 = multiLink1 + multiLink2;
	bool local3 = multiLink4 != nullptr;
	bool local4 = multiLink4->isContain( elem1 )
		&& multiLink4->isContain( elem2 )
		&& multiLink4->isContain( elem3 )
		&& multiLink4->isContain( elem4 )
		&& multiLink4->getElements().size() == 4;

	result = result && local1 && local2 && local3 && local4;

	return result;
 }