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
//1.当派生类没有显式定义复制控制函数时，
//而基类有显式定义复制控制函数时，执行
//派生类对象之间的复制操作时，会自动调用
//基类的复制控制函数

class Base
{
public:
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
		cout << _pdata1 << endl;
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
	Derived(const char * pdata)
	: Base(pdata)
	{
	
	}
};


int main(void)
{
	Derived d1("hello");
	d1.display();
	Derived d2 = d1;
	d2.display();

	Derived d3("world");
	d1 = d3;

	

	return 0;
}
