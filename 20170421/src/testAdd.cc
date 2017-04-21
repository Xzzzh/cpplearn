 ///
 /// @file    testAdd.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-21 22:02:17
 //
#include "add.h" 
#include <iostream>
using std::cout;
using std::endl;
//为什么模板不区分头文件和实现文件？
//因为如果区分的话只能推导出一个函数声明
//int add<int>(int, int);
int main(void)
{
	int a = 3, b = 4;
	cout << add(a, b) << endl;

	return 0;
}
