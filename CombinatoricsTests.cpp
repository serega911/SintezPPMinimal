#include <vector>
#include <iostream>
#include <set>

#include "CombinatoricsTests.h"
#include "Types.h"


#include "Element.h"
#include "Permutation.h"
#include "Subset.h"
#include "OrderedSample.h"

NS_CORE_USING

static NS_CORE Element_p elem1 = NS_CORE Element::create( NS_CORE eElement::SUN_GEAR, NS_CORE GearSetNumer( 1 ) );
static NS_CORE Element_p elem2 = NS_CORE Element::create( NS_CORE eElement::EPY_GEAR, NS_CORE GearSetNumer( 1 ) );
static NS_CORE Element_p elem3 = NS_CORE Element::create( NS_CORE eElement::CARRIER, NS_CORE GearSetNumer( 1 ) );
static NS_CORE Element_p elem4 = NS_CORE Element::create( NS_CORE eElement::SUN_GEAR, NS_CORE GearSetNumer( 2 ) );

bool CombinatoricsTests::exec()
{
	return
		premutationsTest()
		&& subsetsTest()
		&& orderedSampleTest()
		;
}

bool CombinatoricsTests::combinatoricTest( combinatoricTestData data, Combinatorics<IObject_p> & combi )
{
	bool result = true;

	do
	{
		Combinatorics<IObject_p>::Values ret = combi.get();

		for ( auto& it : data._ans )
		{
			if ( it.first == ret )
			{
				if ( it.second == false )
					it.second = true;
				else
					result = false;
			}
		}

	} while ( combi.next() );

	for ( const auto& it : data._ans )
	{
		if ( it.second == false )
			result = false;
	}

	return result;
}

bool CombinatoricsTests::premutationsTest()
{
	bool result = true;

	combinatoricTestData tests[1];
	/*n=3*/
	tests[0]._values = { elem1, elem2, elem3 };
	tests[0]._ans =
	{
		{ { elem1, elem2, elem3 }, false },
		{ { elem1, elem3, elem2 }, false },
		{ { elem2, elem1, elem3 }, false },
		{ { elem2, elem3, elem1 }, false },
		{ { elem3, elem2, elem1 }, false },
		{ { elem3, elem1, elem2 }, false },
	};
	/*Test*/
	for ( auto &test : tests )
	{
		Permutation<IObject_p> permutation;
		permutation.init( test._values );
		result = result && combinatoricTest( test, permutation );
	}

	return result;
}

bool CombinatoricsTests::subsetsTest()
{
	bool result = true;

	combinatoricTestData tests[3];
	/*n=4 k=2*/
	tests[0]._values = { elem1, elem2, elem3, elem4 };
	tests[0]._ans =
	{
		{ { elem1, elem2 }, false },
		{ { elem1, elem3 }, false },
		{ { elem1, elem4 }, false },
		{ { elem2, elem3 }, false },
		{ { elem2, elem4 }, false },
		{ { elem3, elem4 }, false },
	};
	/*n=3 k=3*/
	tests[1]._values = { elem1, elem2, elem3 };
	tests[1]._ans =
	{
		{ { elem1, elem2, elem3 }, false },
	};
	/*n=4 k=1*/
	tests[2]._values = { elem1, elem2, elem3, elem4 };
	tests[2]._ans =
	{
		{ { elem1 }, false },
		{ { elem2 }, false },
		{ { elem3 }, false },
		{ { elem4 }, false },
	};
	/*Test*/
	for ( auto &test : tests )
	{
		Subset<IObject_p> subset;
		subset.init( test._values, test._ans[0].first.size() );
		result = result && combinatoricTest( test, subset );
	}

	return result;
}

bool CombinatoricsTests::orderedSampleTest()
{

	bool result = true;

	combinatoricTestData tests[1];
	/*n=4 k=3*/
	tests[0]._values = { elem1, elem2, elem3, elem4 };
	for ( const auto &el1 : tests[0]._values )
		for ( const auto &el2 : tests[0]._values )
			for ( const auto &el3 : tests[0]._values )
				tests[0]._ans.push_back( { { el1, el2, el3 }, false } );
	/*Test*/
	for ( auto &test : tests )
	{
		OrderedSample<IObject_p> orderedSample;
		orderedSample.init( test._values, test._ans[0].first.size() );
		result = result && combinatoricTest( test, orderedSample );
	}

	return result;
}