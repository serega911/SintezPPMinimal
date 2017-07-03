#pragma once

#include <algorithm>

#include "Combinatorics.h"

NS_CORE_START

template <typename T>
class Permutation: public Combinatorics<T>
{
public:

	void init( const Values &values )
	{
		Combinatorics::init( values, values.size() );
	}

	bool next() override
	{
		return std::next_permutation( m_indexes.begin(), m_indexes.end() );
	}

};

NS_END