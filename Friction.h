#pragma once

#include <set>

#include "CoreDefines.h"
#include "MultiLink.h"
#include "IObject.h"
#include "ISchemeElement.h"

NS_CORE_START

SHARED_PTR( Friction, Friction_p )

class Friction : public IObject, ISchemeElement
{
private:

	
	MultiLink_p									m_left;
	MultiLink_p									m_right;
	FrictionNumer								m_number;

	Friction( const MultiLink_p& left, const MultiLink_p& right, const FrictionNumer& number );
	Friction() = delete;
	Friction( const Friction& obj );



public:

	static Friction_p							create( const MultiLink_p& left, const MultiLink_p& right, const FrictionNumer& number );
	Friction_p									clone() const;
	const MultiLink_p&							getLeftMultiLink() const;
	const MultiLink_p&							getRightMultiLink() const;
	//virtual void								writeToFile( std::ostream& file ) const override;
	//virtual void								writeToConsole() const override;

};

NS_END