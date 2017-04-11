 ///
 /// @file    string.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-11 19:59:53
 ///
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void test0(void)
{
	char str[] = "hello, world";
	char str2[] = "shenzhen";
	int len1 = sizeof(str);
	int len2 = sizeof(str2);
	cout << "len1 = " << len1 << ", len2 = " << len2 << endl;
	strcat(str2, str);//第一个参数代表的数组空间一定要是足够，拼接字符串之后不能越界
	printf("%s\n", str);
	printf("%s\n", str2);
	printf("str = %p\n", str);
	printf("str2 = %p\n", str2);
}
