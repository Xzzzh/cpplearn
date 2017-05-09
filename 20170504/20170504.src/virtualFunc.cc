 ///
 /// @file    virtualFunc.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-04 11:32:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Base
{
public:
	virtual int func(int x)
	{
		cout << "Base::func(int)" << endl;
		return x;
	}
};

//一旦基类定义了虚函数之后，派生类的虚函数形式一定要与基类保持一致
class Derived : public Base
{
public:
	virtual float func(int x)
	{
		cout << "Derived::func(int)" << endl;
		return (float)x;
	}
};

int main(void)
{
	
	return 0;
}
