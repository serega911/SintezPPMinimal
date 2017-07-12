#include "UnitGenerate.h"

#include "Code.h"
#include "eElement.h"
#include "GlobalInfo.h"
#include "Subset.h"


void UnitGenerate::run()
{
	NS_CORE GlobalInfo::GlobalData data;
	data._gearSetsCount = NS_CORE GearSetNumer( 3 );
	data._w = NS_CORE FreedomDegree( 3 );
	NS_CORE GlobalInfo::getInstance()->init( data );


	prepareLinks();
	generateInOut();
}

void UnitGenerate::prepareLinks()
{
	NS_CORE GearSetNumer max = NS_CORE GlobalInfo::getInstance()->getData()->_gearSetsCount;

	for ( NS_CORE GearSetNumer gearSet1( 1 ); gearSet1 <= max; ++gearSet1 )
	{
		for ( const auto& eelem1 : NS_CORE c_centraleElements )
		{
			for ( NS_CORE GearSetNumer gearSet2( gearSet1 + NS_CORE GearSetNumer( 1 ) ); gearSet2 <= max; ++gearSet2 )
			{
				for ( const auto& eelem2 : NS_CORE c_centraleElements )
				{
					Link link;
					link.first = NS_CORE Element::create( eelem1, gearSet1 );
					link.second = NS_CORE Element::create( eelem2, gearSet2 );
					m_links.push_back( link );
				}
			}
		}
	}
}

void UnitGenerate::generateInOut()
{
	NS_CORE GearSetNumer max = NS_CORE GlobalInfo::getInstance()->getData()->_gearSetsCount;

	for ( NS_CORE GearSetNumer gearSetIn( 1 ); gearSetIn <= max; ++gearSetIn )
	{
		for ( const auto& eelemIn : NS_CORE c_centraleElements )
		{
			for ( NS_CORE GearSetNumer gearSetOut( 1 ); gearSetOut <= max; ++gearSetOut )
			{
				for ( const auto& eelemOut : NS_CORE c_centraleElements )
				{
					auto input = NS_CORE Element::create( eelemIn, gearSetIn );
					auto output = NS_CORE Element::create( eelemOut, gearSetOut );

					if ( input != output )
					{
						Code_p code = Code::create();
						code->setInput( input );
						code->setOutput( output );
						generateLinks(code);
					}
				}
			}
		}
	}
}

void UnitGenerate::generateLinks(const Code_p& code)
{
	const size_t linksCount = 3;
	NS_CORE Subset<Link> subset;
	subset.init(m_links, linksCount);

	do
	{
		auto clone = code->clone();
		for (const auto &link : subset.get())
			clone->addLink(link.first, link.second);

		//TODO check

		generateFrictions(clone);
	} while (subset.next());

}

void UnitGenerate::generateFrictions(const Code_p& code)
{
	const size_t frictionsCount = 3;

	typedef std::pair<NS_CORE Element_p, NS_CORE Element_p> Friction;

	std::vector<Friction> allFrictions;

	NS_CORE Subset<NS_CORE Element_p> subset;
	auto elements = code->getElementsForFrictions();
	subset.init(elements, 2);
	do
	{
		Friction friction;
		friction.first = subset.get()[0];
		friction.second = subset.get()[1];
		allFrictions.push_back(friction);
	} while (subset.next());

	NS_CORE Subset<Friction> subset1;
	subset1.init(allFrictions, frictionsCount);
	do
	{
		auto clone = code->clone();
		for (const auto& friction : subset1.get())
			clone->addFriction(friction.first, friction.second);
		generateBrakes(clone);
	} while (subset1.next());
}

void UnitGenerate::generateBrakes(const Code_p& code)
{
	const size_t brakesCount = 3;
	
	NS_CORE Subset<NS_CORE Element_p> subset;
	auto elements = code->getElementsForFrictions();
	subset.init(elements, brakesCount);

	do
	{
		auto clone = code->clone();
		for (const auto &brake : subset.get())
			clone->addBrake(brake);


		//TODO check

		checkAndFinish(clone);
	} while (subset.next());

}

void UnitGenerate::checkAndFinish(const Code_p& code)
{
	//TODO
}

bool UnitGenerate::checkRequirements() const
{
	return true;
}
