 ///
 /// @file    template1.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-21 20:43:22
 ///
#include <string.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

//函数模板
//把模板看成是一个代码生成器，是由具体的实参进行模板参数推倒来完成的
#if 1
template <typename T>
T add(T a, T b)
{
	cout << "T add(T a, T b)" << endl;
	return a + b;
}
#endif

template <typename T>
T add(T a, T b, T c)
{
	cout << "T add(T a, T b, T c)" << endl;
	return a + b + c;
}

#if 0
//模板函数是由模板生成的函数
int add(int a, int b)
{
	return a + b;
}

double add(double a, double b)
{
	return a + b;
}
#endif
//函数模板和普通函数可以重载,进行函数调用时， 自由函数会优先于模板函数的调用
int add(int a, int b)
{
	cout << "int add(int a, int b)" << endl;
	return a + b;
}

const char * add(const char * a, const char * b)
{
	cout << "const char *  add()" << endl;
	char * ptmp = new char[strlen(a) + strlen(b) + 1];
	strcpy(ptmp, a);
	strcat(ptmp, b);
	return ptmp;
}
//模板特化，不能独立存在
template <>
const char * add(const char * a, const char * b)
{
	cout << "template <> const char * add(const char *, const char *)" << endl;
	char * ptmp = new char[strlen(a) + strlen(b) + 1];
	strcpy(ptmp, a);
	strcat(ptmp, b);
	return ptmp;
}

int main(void)
{
	int a = 3, b = 4;
	double c = 3.3, d = 4.4, e = 5.5;
	string s1("hello");
	string s2(",world");

	const char * p1 = "hello";
	const char * p2 = ",world";

	cout << add(a, b) << endl;//函数模板的隐式实例化
	cout << add<double>(c, d) << endl;//函数模板的显式实例化
	cout << add(s1, s2) << endl;
	cout << add(p1, p2) << endl;
	cout << add(c, d, e) << endl;

	return 0;
}
