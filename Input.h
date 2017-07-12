#pragma once

#include <set>
#include <memory>

#include "CoreDefines.h"
#include "MultiLink.h"
#include "IObject.h"
#include "ISchemeElement.h"

NS_CORE_START

SHARED_PTR( Input, Input_p )

class Input : public IObject, ISchemeElement
{
private:

	MultiLink_p									m_multiLink;

	Input( const MultiLink_p& left );
	Input() = delete;
	Input( const Input& obj);

public:

	static Input_p								create( const MultiLink_p& multiLink );
	const MultiLink_p&							getMultiLink() const;
	Input_p										clone() const;
	//virtual void								writeToFile( std::ostream& file ) const override;
	//virtual void								writeToConsole() const override;

};

NS_END