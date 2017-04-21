 ///
 /// @file    atexit.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-20 21:39:03
 ///
#include <stdlib.h> 
#include <iostream>
using std::cout;
using std::endl;

void print()
{
	cout << "print()" << endl;
}

int main(void)
{
	cout << "Hello, world!" << endl;
	//当main退出时，atexit注册的函数会被自动调用，
	//同一个函数，注册几次就会被调用几次
	atexit(print);//注册的传参是函数指针（函数名）
	atexit(print);
	cout << "main exit" << endl;
	//可以看到调用时机为return语句之前
	return 0;
}
