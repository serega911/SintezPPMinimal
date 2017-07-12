#include "Friction.h"

NS_CORE_USING

Friction::Friction( const MultiLink_p& left, const MultiLink_p& right, const FrictionNumer& number )
: m_left( left ), m_right( right ), m_number( number )
{
}

Friction::Friction(const Friction& obj)
{
	m_number = obj.m_number;
	m_left = obj.m_left->clone();
	m_right = obj.m_right->clone();
}

Core::Friction_p Friction::create( const MultiLink_p& left, const MultiLink_p& right, const FrictionNumer& number )
{
	return Friction_p( new Friction(left, right, number) );
}

Friction_p Friction::clone() const
{
	return Friction_p(new Friction(*this));
}

const MultiLink_p& Friction::getLeftMultiLink() const
{
	return m_left;
}

const MultiLink_p& Friction::getRightMultiLink() const
{
	return m_right;
}