 ///
 /// @file    multiDerived.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-03 16:27:22
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class A
{
public:
	void print()
	{	cout << "A::print()" << endl;	}
};

class B
{
public:
	void print()
	{	cout << "B::print()" << endl;	}
};


//多重继承时，发生的是命名冲突，可以采用作用域限定符解决
class C : public A, public B
{
public:
	void show()
	{
		A::print();
		B::print();
	}
};

int main(void)
{
	C c;
	c.show();
	c.B::print();
}
