#pragma once

#include "CoreDefines.h"
#include "ITest.h"
#include "Combinatorics.h"
#include "IObject.h"

NS_CORE_START

class CombinatoricsTests : ITest
{
private:

	struct combinatoricTestData
	{
		Combinatorics<IObject_p>::Values _values;
		std::vector<std::pair<Combinatorics<IObject_p>::Values, bool>> _ans;
	};

	bool combinatoricTest( combinatoricTestData data, Combinatorics<IObject_p> & combi );
	bool premutationsTest();
	bool subsetsTest();
	bool orderedSampleTest();

public:
	virtual bool								exec() override;
};

NS_END