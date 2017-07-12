#pragma once

#include <set>

#include "CoreDefines.h"
#include "MultiLink.h"
#include "IObject.h"
#include "ISchemeElement.h"

NS_CORE_START

SHARED_PTR( Output, Output_p )

class Output : public IObject, ISchemeElement
{
private:

	MultiLink_p									m_multiLink;

	Output( const MultiLink_p& left );
	Output() = delete;
	Output( const Output& );

public:

	Output_p										clone() const;
	static Output_p								create( const MultiLink_p& multiLink );
	const MultiLink_p&							getMultiLink() const;
	//virtual void								writeToFile( std::ostream& file ) const override;
	//virtual void								writeToConsole() const override;

};

NS_END