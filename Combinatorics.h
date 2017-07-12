#pragma once
#include <vector>

#include "CoreDefines.h"

NS_CORE_START

template <typename T>
class Combinatorics
{
public:

	typedef std::vector<T> Values;

protected:

	typedef std::vector<size_t> Combinations;

	Values										m_values;
	Combinations								m_indexes;

public:

	virtual bool								next() = 0;

	virtual void init( const Values& values, const size_t k )
	{
		m_values = values;

		m_indexes.resize( k );
		for ( size_t i = 0; i < k; i++ )
			m_indexes[i] = i;
	}

	Values get() const
	{
		Values ans;
		for ( const auto &it : m_indexes )
			ans.emplace_back( m_values.at( it ) );
		return ans;
	}

};

NS_END