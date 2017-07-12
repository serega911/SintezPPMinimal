#pragma once

#include <set>

#include "CoreDefines.h"
#include "MultiLink.h"
#include "IObject.h"
#include "ISchemeElement.h"

NS_CORE_START

SHARED_PTR( Brake, Brake_p )

class Brake : public IObject, ISchemeElement
{
private:

	MultiLink_p									m_multiLink;
	BrakeNumer									m_number;

	Brake( const MultiLink_p& left, const BrakeNumer& number );
	Brake() = delete;
	Brake( const Brake& obj );

public:

	static Brake_p								create( const MultiLink_p& multiLink, const BrakeNumer& number );
	Brake_p										clone() const;
	const MultiLink_p&							getMultiLink() const;
	//virtual void								writeToFile( std::ostream& file ) const override;
	//virtual void								writeToConsole() const override;

};

NS_END