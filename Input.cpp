#include "Input.h"

NS_CORE_USING

Input::Input( const MultiLink_p& left )
: m_multiLink( left )
{
}

Input::Input(const Input& obj)
{
	m_multiLink = obj.m_multiLink->clone();
}

Input_p Input::create( const MultiLink_p& multiLink )
{
	return Input_p( new Input( multiLink ) );
}

Input_p Input::clone() const
{
	return  Input_p(new Input(*this));
}

const MultiLink_p& Input::getMultiLink() const
{
	return m_multiLink;
}