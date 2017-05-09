 ///
 /// @file    oversee.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-04 10:04:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	int func(double x)
	{
		cout << "Base::func(int)" << endl;
		return _ix;
	}
protected:
	int _ix;
};

class Derived :public Base
{
public:

	int func(int x)//对于成员函数而言，如果有与基类相同的名字，基类的成员被隐藏
	{
		cout << "Derived::func(int)" << endl;
		_ix = 9;//由于基类的数据成员与派生类的数据成员名字相同，此时在访问时基类的被隐藏
		Base::_ix = 20;
		cout << "_ix = " << _ix << endl;
		cout << "Base::_ix = " << Base::_ix << endl;
		return _ix;
	}

	int _ix;
};

int main(void)
{
	Derived d1;
	d1.func(3.3);
	d1.Base::func(3);
	return 0;
}
