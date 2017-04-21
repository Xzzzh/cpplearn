 ///
 /// @file    add.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-21 22:06:30
 ///
#include "add.h" 
#include <iostream>
using std::cout;
using std::endl;

//函数模板的实现
template <typename T>
T add(T a, T b)
{
	return a + b;
}
