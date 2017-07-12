#include "Output.h"

NS_CORE_USING

Output::Output( const MultiLink_p& left )
: m_multiLink( left )
{
}

Output::Output(const Output& obj)
{
	m_multiLink = obj.m_multiLink->clone();
}

Output_p Output::create( const MultiLink_p& multiLink )
{
	return Output_p( new Output( multiLink ) );
}

Output_p Output::clone() const
{
	return  Output_p(new Output(*this));
}

const MultiLink_p& Output::getMultiLink() const
{
	return m_multiLink;
}