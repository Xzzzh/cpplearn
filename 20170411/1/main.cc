 ///
 /// @file    main.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-11 20:59:01
 ///
#include "Computer.h" 
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	Computer com;
	com.setBrand("thinkpad");
	com.setPrice(10000);
	com.print();

	return 0;
}

