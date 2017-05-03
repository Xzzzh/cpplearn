 ///
 /// @file    constructorDerviedClass.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-03 17:00:05
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//1. 基类没有显式定义构造函数，但派生类有显式定义构造函数
//   创建派生类对象时，会自动调用基类的无参构造函数
class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}

};

class Derived : public Base
{
public:
	Derived()
	{
		cout << "Derived()" << endl;
	}

	Derived(int ix)
	{
		cout << "Derived(int)" << endl;
	}
};

int main(void)
{
	Derived d1;

	Derived d2(1);
	
	return 0;
}
