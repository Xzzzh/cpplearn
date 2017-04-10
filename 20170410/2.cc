 ///
 /// @file    2.cc
 /// @author  lemon(sjzxzh@yeah.net)
 /// @date    2017-04-10 15:24:01
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int & func()
{
	int x = 4;
	return x;
}
int main()
{
	func();
	cout << "func() = " << func() << endl;
	return 0;
}
