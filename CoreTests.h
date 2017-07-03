#pragma once

#include "CoreDefines.h"
#include "ITest.h"

NS_CORE_START

class CoreTest: ITest
{
private:

	bool eElementTest();
	bool elementTest();
	bool multiLinkTest();

public:
	virtual bool								exec() override;
};

NS_END