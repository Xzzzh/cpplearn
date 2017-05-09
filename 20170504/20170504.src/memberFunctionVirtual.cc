 ///
 /// @file    memberFunctionVirtual.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-04 14:52:00
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

	void callBase1()
	{
		this->display();
	}

	void callBase2()
	{
		Base::display();
	}
};

class Child : public Base
{
public:
	void display()
	{
		cout << "Child::display()" << endl;
	}

	void callChild1()
	{
		this->display();
	}

	void callChild2()
	{
		Child::display();
	}
};

int main(void)
{
	Base base;
	Child child;

	base.callBase1();
	child.callBase1();
	//child.callChild1();

	Base * pbase = &base;
	pbase->callBase1();
	pbase->callBase2();
	cout << endl;

	pbase = &child;
	pbase->callBase1();
	//pbase->callChild1();
	pbase->callBase2();

	return 0;
}
