#pragma once

#include <memory>
#include <map>

#include "CoreDefines.h"
#include "MultiLink.h"
#include "Friction.h"
#include "Brake.h"
#include "Input.h"
#include "Output.h"

NS_CORE_START

SHARED_PTR( Code, Code_p )

class Code : public IObject
{
public:

	//virtual void								writeToFile( std::ostream& file ) const override;
	//virtual void								writeToConsole() const override;

	bool										isSame(const Code_p& code) const;

	static Code_p								create();
	Code_p										clone() const;

	bool										setInput( const Element_p& input );
	bool										setOutput( const Element_p& output );
	bool										addLink( const Element_p& elem1, const Element_p& elem2 );
	bool										addFriction(const Element_p& elem1, const Element_p& elem2);
	bool										addBrake(const Element_p& elem1);
	bool										addElement(const Element_p& elem1);

	const std::set<MultiLink_p>&				getMultiLinks() const;
	const Input_p								getInput() const;
	const Output_p								getOutput() const;

protected:

	Code( const Code& obj );
	Code();

private:

	std::set<MultiLink_p>						m_multiLinks;
	std::map<FrictionNumer, Friction_p>			m_frictions;
	std::map<BrakeNumer, Brake_p>				m_brakes;
	Input_p										m_input;
	Output_p									m_output;

	FrictionNumer								m_frictionsCount;
	BrakeNumer									m_brakesCount;
};

NS_END