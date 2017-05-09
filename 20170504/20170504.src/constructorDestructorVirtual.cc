 ///
 /// @file    constructorDestructorVirtual.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-04 15:03:50
 ///
 
#include <iostream>
using std::cout;
using std::endl;


//为什么构造函数不能是虚函数？
//答:虚函数的使用是对象创建完毕之后才有的，
//	 而构造函数是用来创建对象的，
class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}

	virtual
	void func1()
	{
		cout << "Base::func1()"  << endl;
	}

	virtual
	void func2()
	{
		cout << "Base::func2()"  << endl;
	}

	~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Base1 : public Base
{
public:
	Base1()
	: Base()
	{
		func1();//在构造函数或者析构函数之中调用虚函数，采用的是静态联编
		cout << "Base1()" << endl;
	}

	virtual void func1()
	{
		cout << "Base1::func1()" << endl;
	}

	virtual void func2()
	{
		cout << "Base1::func2()" << endl;
	}

	~Base1()
	{
		cout << "~Base1()" << endl;
		func2();
	}
};


class Sub : public Base1
{
public:
	Sub()
	: Base1()
	{
		cout << "Sub()" << endl;
	}

	virtual void func1()
	{
		cout << "Sub::func1()" << endl;
	}

	virtual void func2()
	{
		cout << "Sub::func2()" << endl;
	}

	~Sub()
	{
		cout << "~Sub()" << endl;
	}
};


int main(void)
{
	Sub sub;
	return 0;
}
