 ///
 /// @file    namespace.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-10 21:20:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;
#if 0
int distance()
{
	return 1;
}
#endif

void test()
{
	cout << endl;
}
void displayA()
{
	cout << "displayA()" << endl;
}
namespace A
{
void displayA()
{
	std::cout << "A::displayA()" << std::endl;
}
}//end of namespace A

namespace B
{
	void displayB()
	{
		displayA();
	}
}//end of namespace B

int main(void)
{
	A::displayA();
	displayA();
	return 0;
}
