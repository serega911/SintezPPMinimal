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

	virtual int count()
	{
		return count(m_indexes.size());
	}

	static int count(const int n)
	{
		return factorial(n);
	}
};

NS_END