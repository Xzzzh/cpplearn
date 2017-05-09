 ///
 /// @file    virtual2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-04 11:37:29
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	virtual 
	void display()
	{
		cout << "Base::display()" << endl;
	}
private:
	double _dx;
};

class Child1 : public Base
{
public:
	void display()
	{
		cout << "Child1::display()" << endl;
	}
};

class Child2 : public Base
{
public:
	void display()
	{
		cout << "Child2::display()" << endl;
	}
};

//虚函数机制被激活的时机：
//1.　基类定义了虚函数，派生类覆盖了基类的虚函数
//2.  通过一个基类的指针或者引用指向了派生类对象
//3.  通过该指针或引用调用虚函数

void display(Base * pbase)
{
	pbase->display();
}

int main(void)
{
	cout << " sizeof(Base) = " << sizeof(Base) << endl;
	cout << " sizeof(Child1) = " << sizeof(Child1) << endl;
	cout << " sizeof(Child2) = " << sizeof(Child2) << endl;
	Base base;
	Child1 child1;
	Child2 child2;

	display(&base);
	display(&child1);
	display(&child2);
	cout << endl;

	base.display();//采用对象名的方式进行访问,虚函数并不表现出虚函数的特性
	child1.display();//直接去方法区找相应的函数
	child2.display();//体现的是隐藏,隐藏基类相应的方法
	cout << endl;

	Base & ref = child1;
	ref.display();

	return 0;
}
