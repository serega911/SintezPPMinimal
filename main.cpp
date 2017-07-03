#include <iostream>

#include "CoreTests.h"
#include "CombinatoricsTests.h"


int main()
{
	NS_CORE CoreTest test1;
	NS_CORE CombinatoricsTests test2;

	bool result = test1.exec() && test2.exec();

	std::cout << result << std::endl;

	system("pause");
}