#include <set>

#include "Code.h"

NS_CORE_USING

Code::Code()
: m_frictionsCount( 0 ), m_brakesCount( 0 )
{
}

Code::Code(const Code& obj)
{
	std::set<MultiLink_p> clonnedLinks;

	m_input = obj.m_input->clone();
	clonnedLinks.insert(obj.m_input->getMultiLink());
	m_multiLinks.insert(m_input->getMultiLink());

	m_output = obj.m_output->clone();
	clonnedLinks.insert(obj.m_output->getMultiLink());
	m_multiLinks.insert(m_output->getMultiLink());

	for (const auto& friction : obj.m_frictions)
	{
		Friction_p frictionClone = friction.second->clone();
		m_frictions[friction.first] = frictionClone;
		m_multiLinks.insert(frictionClone->getLeftMultiLink());
		m_multiLinks.insert(frictionClone->getRightMultiLink());
		clonnedLinks.insert(friction.second->getLeftMultiLink());
		clonnedLinks.insert(friction.second->getRightMultiLink());
	}

	for (const auto& brake : obj.m_brakes)
	{
		Brake_p brakeClone = brake.second->clone();
		clonnedLinks.insert(brake.second->getMultiLink());
		m_multiLinks.insert(brakeClone->getMultiLink());
	}

	for (const auto& multiLink : obj.m_multiLinks)
		if (clonnedLinks.find(multiLink) == clonnedLinks.end())
			m_multiLinks.insert(multiLink->clone());
}

Code_p Core::Code::create()
{
	return Code_p( new Code );
}

Code_p Core::Code::clone() const
{
	return Code_p(new Code(*this));
}

bool Core::Code::setInput( const Element_p& input )
{
	MultiLink_p multiLink = MultiLink::create();
	multiLink->addElement( input );
	m_input = Input::create( multiLink );
	m_multiLinks.insert( multiLink );

	return m_input != nullptr;
}

bool Core::Code::setOutput( const Element_p& output )
{
	MultiLink_p multiLink = MultiLink::create();
	multiLink->addElement( output );
	m_output = Output::create( multiLink );
	m_multiLinks.insert( multiLink );

	return m_output != nullptr;
}

bool Core::Code::addLink( const Element_p& elem1, const Element_p& elem2 )
{
	MultiLink_p ml1 = nullptr;
	MultiLink_p ml2 = nullptr;

	for ( auto& multiLink : m_multiLinks )
	{
		if ( multiLink->isContain( elem1 ) )
		{
			multiLink->addElement( elem2 );
			ml1 = multiLink;
		}
		else if ( multiLink->isContain( elem2 ) )
		{
			multiLink->addElement( elem1 );
			ml2 = multiLink;
		}
	}

	if ( !ml1 && !ml2 )
	{
		MultiLink_p multiLink = MultiLink::create();
		multiLink->addElement( elem1 );
		multiLink->addElement( elem2 );
		m_multiLinks.insert( multiLink );
	}
	else if (ml1 && ml2)
	{
		if (ml1.use_count() == 2)
		{
			ml2 += ml1;
			m_multiLinks.erase(ml1);
		}
		else if (ml2.use_count() == 2)
		{
			ml1 += ml2;
			m_multiLinks.erase(ml2);
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool Core::Code::addFriction(const Element_p& elem1, const Element_p& elem2)
{
	++m_frictionsCount;

	MultiLink_p left = nullptr;
	MultiLink_p right = nullptr;

	for (const auto& multilink : m_multiLinks)
	{
		if (multilink->isContain(elem1))
			left = multilink;
		else if (multilink->isContain(elem2))
			right = multilink;
	}

	if (!left || !right)
	{
		return false;
	}

	m_frictions[m_frictionsCount] = Friction::create( left, right, m_frictionsCount );
	return true;
}

bool Core::Code::addBrake(const Element_p& elem1)
{
	++m_brakesCount;
	MultiLink_p left = nullptr;

	for (const auto& multilink : m_multiLinks)
	{
		if (multilink->isContain(elem1))
		{
			left = multilink;
			break;
		}
			
	}

	if (!left)
		return false;

	m_brakes[m_brakesCount] = Brake::create(left, m_brakesCount);
	return true;
}

bool Core::Code::addElement(const Element_p& elem1)
{
	for (const auto& multilink : m_multiLinks)
	{
		if (multilink->isContain(elem1))
		{
			return false;
		}
	}

	MultiLink_p multiLink = MultiLink::create();
	multiLink->addElement(elem1);
	m_multiLinks.insert(multiLink);
	return true;
}

const std::set<MultiLink_p>& Core::Code::getMultiLinks() const
{
	return m_multiLinks;
}

const Input_p Code::getInput() const
{
	return m_input;
}

const Output_p Code::getOutput() const
{
	return m_output;
}

bool Code::isSame(const Code_p& code) const
{
	for (const MultiLink_p& my_ml : m_multiLinks)
	{
		bool isFinded = false;
		for (const MultiLink_p& their_ml : code->m_multiLinks)
		{
			if ((*my_ml.get()) == (*their_ml.get()))
			{
				isFinded = true;
				break;
			}
		}

		if (!isFinded)
			return false;
	}

	return true;
}