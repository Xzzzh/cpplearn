 ///
 /// @file    empty.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-12 21:13:15
 ///
#include <stdio.h> 
#include <iostream>
using std::cout;
using std::endl;

class Empty
{};

int main(void)
{
	cout << sizeof(Empty) << endl;

	Empty e1;
	Empty e2;

	printf("&e1 = %p\n", &e1);
	printf("&e2 = %p\n", &e2);
	
}
