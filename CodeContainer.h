#pragma once

#include <set>
#include <map>

#include "Element.h"
#include "Code.h"

class CodeContainer
{
private:

	typedef std::pair<NS_CORE Element_p, NS_CORE Element_p> Key;
	typedef std::set<NS_CORE Code_p> Container;

	std::map<Key, Container> m_codes;

public:

	bool add( const NS_CORE Code_p code );

};