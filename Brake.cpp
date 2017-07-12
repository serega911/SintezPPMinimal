#include "Brake.h"

NS_CORE_USING

Brake::Brake( const MultiLink_p& left, const BrakeNumer& number )
: m_multiLink( left ), m_number( number )
{
}

Brake::Brake(const Brake& obj)
{
	m_multiLink = obj.m_multiLink->clone();
	m_number = obj.m_number;
}

Brake_p Brake::create( const MultiLink_p& multiLink, const BrakeNumer& number )
{
	return Brake_p( new Brake( multiLink, number ) );
}

Brake_p Brake::clone() const
{
	return Brake_p(new Brake(*this));
}

const MultiLink_p& Brake::getMultiLink() const
{
	return m_multiLink;
}