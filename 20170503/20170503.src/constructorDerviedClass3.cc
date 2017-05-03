 ///
 /// @file    constructorDerviedClass.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-03 17:00:05
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//3. 基类有显式定义构造函数，但派生类有显式定义构造函数
//	
//   创建派生类对象时，如果希望调用的是基类的有参构造函数，
//   则必须要在派生类构造函数的初始化列表之中显式调用基类
//   的有参构造函数
class Base
{
public:
	Base()
	: _ix(0)
	{
		cout << "Base()" << endl;
	}
	Base(int ix)
	: _ix(ix)
	{
		cout << "Base(int)" << endl;
	}

	~Base()
	{
		cout << "~Base()" << endl;
	}

	void display()const
	{	cout << "Base::_ix = " << _ix << endl;	}
private:
	int _ix;
};

class Derived : public Base
{
public:
	Derived()
	: Base()
	{
		cout << "Derived()" << endl;
	}

	Derived(int ix)
	: Base(ix) //显式调用基类构造函数
	{
		cout << "Derived(int)" << endl;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
	}
};

int main(void)
{
	Derived d1;
	d1.display();

	Derived d2(1);
	d2.display();
	
	return 0;
}
