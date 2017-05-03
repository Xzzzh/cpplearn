 ///
 /// @file    constructorDerviedClass.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-03 17:00:05
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//2. 基类有显式定义构造函数，但派生类没有显式定义构造函数
//   创建派生类对象时，会自动调用基类的无参构造函数,此时
//   在基类内部必须显式定义无参构造函数
class Base
{
public:
#if 1
	Base()
	{
		cout << "Base()" << endl;
	}
#endif

	Base(int ix)
	{
		cout << "ix = " << ix << endl;
	}

};

class Derived : public Base
{
public:
};

int main(void)
{
	Derived d1;
	
	return 0;
}
