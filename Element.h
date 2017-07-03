#pragma once

#include <memory>

#include "IObject.h"
#include "CoreDefines.h"
#include "Types.h"
#include "eElement.h"

NS_CORE_START

SHARED_PTR( Element, Element_p )

class Element: public IObject
{
public:

	virtual void								writeToFile( std::ostream& file ) const override;
	virtual void								writeToConsole() const override;

	static Element_p							create( eElement type, GearSetNumer gearSetNumber );

	const eElement&								getType() const;
	const GearSetNumer&							getGearSetNumer() const;

private:

	Element() = delete;
	Element(const Element&) = delete;
	Element( eElement type, GearSetNumer gearSetNumber );

	GearSetNumer								m_gearSet;
	eElement									m_type;
};

NS_END