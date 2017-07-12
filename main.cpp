#include <iostream>

#include "CoreTests.h"
#include "CombinatoricsTests.h"
#include "UnitGenerate.h"

int main()
{
// 	NS_CORE CoreTest test1;
// 	NS_CORE CombinatoricsTests test2;
// 
// 	bool result = test1.exec() && test2.exec();
// 
// 	std::cout << result << std::endl;

	UnitGenerate generate;
	generate.run();

	system("pause");
}