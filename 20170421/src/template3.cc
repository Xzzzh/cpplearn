 ///
 /// @file    template3.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-21 21:08:32
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//模板参数有两种形式：
//1.使用class或者typename修饰的类 类型
//2.非类型参数，一般用int来表示
template <typename T, int NUM>
T func(T a);

int main(void)
{
	int a = 3;
	cout << func<int, 10>(a) << endl;
	return 0;
}

//函数模板是可以分成声明与实现的，但是必须要在同一个文件(模块)中
template <typename T, int NUM>
T func(T a)
{
	return a * NUM;
}
