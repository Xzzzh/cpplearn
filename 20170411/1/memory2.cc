 ///
 /// @file    memory2.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-11 20:25:35
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

int a = 10;

const int b = 20;//位于文字常量区

int main(void)
{
	int c = 30;
	const int d = 40;

	const char *p = "123456";

	printf("&a全局变量 = %p\n", &a);
	printf("&b位于文字常量区 = %p\n", &b);
	printf("&c栈空间 = %p\n", &c);
	printf("&d常量空间 = %p\n", &d);
	printf("p字符常量指针 = %p\n", p);

	return 0;
}
