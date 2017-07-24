#pragma once

#include "Combinatorics.h"

NS_CORE_START

template <typename T>
class OrderedSample : public Combinatorics<T>
{
public:

	virtual void init( const Values& values, const size_t k ) override
	{
		m_values = values;

		m_indexes.resize( k );
		for ( size_t i = 0; i < k; i++ )
			m_indexes[i] = 0;
	}

	bool next() override
	{
		const size_t min_value = 0;
		const size_t k = m_indexes .size();
		const size_t n = m_values.size();

		for ( int i = k - 1; i >= 0; --i )
		{
			if ( m_indexes[i] < n - 1 )
			{
				++m_indexes[i];
				return true;
			}
			else
			{
				m_indexes[i] = min_value;
			}
		}

		return false;
	}

	virtual int count()
	{
		return count(m_values.size(), m_indexes.size());
	}

	static int count(const int n, const int k)
	{
		return pow(n,k);
	}
};

NS_END