 ///
 /// @file    namespace.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-11 19:45:31
 ///
 
#include <iostream>
using std::cout;
using std::endl;

struct C
{
	int a;
	int b;
	int c;
};

namespace B
{
	int num = 100;
}

namespace A
{
	void displayA()
	{
		cout << "B::num = " << B::num << endl;
		cout << "A::displayA()" << endl;
	}
}

namespace B
{
//	int num = 100;不能两次重复定义
	void displayB()
	{
		cout << "B::displayB()" << endl;
	}
}
