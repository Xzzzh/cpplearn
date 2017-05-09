 ///
 /// @file    Derived1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-04 11:02:09
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

//派生类与派生类的复制控制：
//2.当派生类有显式定义复制控制函数时，
//而基类有显式定义复制控制函数时，执行
//派生类对象之间的复制操作时，不会再自动调用
//基类的复制控制函数,而需要手动显式调用相应的
//复制控制函数

class Base
{
public:

	Base()
	: _pdata1(new char[1])
	{
		cout << "Base()" << endl;
		_pdata1[0] = '\0';
	}

	Base(const char * pdata)
	: _pdata1(new char[strlen(pdata) + 1])
	{
		strcpy(_pdata1, pdata);
	}

	Base(const Base &rhs)
	: _pdata1(new char[strlen(rhs._pdata1) + 1])
	{
		strcpy(_pdata1, rhs._pdata1);
		cout << "Base(const Base &)" << endl;
	}

	Base & operator=(const Base & rhs)
	{
		cout << "Base & operator=(const Base&)" << endl;
		if(this != & rhs)
		{
			delete [] _pdata1;
			_pdata1 = new char[strlen(rhs._pdata1) + 1];
			strcpy(_pdata1, rhs._pdata1);
		}
		return *this;
	}

	void display()
	{
		cout << _pdata1;
	}

	~Base()
	{
		delete [] _pdata1;
	}

private:
	char * _pdata1;
};

class Derived : public Base
{ 
public: 
	Derived(const char * pdata1, const char * pdata2)
	: Base(pdata1)
	, _pdata2(new char[strlen(pdata2) + 1])
	{
		strcpy(_pdata2, pdata2);
	}

	Derived(const Derived & rhs)
	: Base(rhs)
	, _pdata2(new char[strlen(rhs._pdata2) + 1])
	{
		strcpy(_pdata2, rhs._pdata2);
	}

	Derived & operator=(const Derived & rhs)
	{
		if(this != &rhs)
		{
			Base::operator=(rhs);

			delete [] _pdata2;
			_pdata2 = new char[strlen(rhs._pdata2) + 1];
			strcpy(_pdata2, rhs._pdata2);
		}
		return *this;
	}

	void display()
	{
		Base::display();
		cout << _pdata2 << endl;
	}

private:
	char * _pdata2;
};


int main(void)
{
	Derived d1("hello", ",world");
	d1.display();
	Derived d2 = d1;
	d2.display();
	cout << "赋值：" << endl;

	Derived d3("shenzhen", "wangdao");
	d3.display();
	d1 = d3;
	
	d1.display();

	return 0;
}
