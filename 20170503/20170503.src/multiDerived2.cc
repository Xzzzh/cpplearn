 ///
 /// @file    multiDerived2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-03 16:32:46
 ///
 
#include <iostream>
using std::cout;
using std::endl;


//菱形继承时如果出现二义性，叫做存储二义性
class A
{
public:
	A(int ix = 0) : _ix(ix){}

	void setX(int ix)
	{
		_ix = ix;
	}

	void display()
	{
		cout << "A::_ix = " << _ix << endl;
	}
private:
	int _ix;
};


class B : virtual public A
{};

class C : virtual public A
{};

class D : public B, public C
{
public:
	D(int ix): A(ix){}

};

int main(void)
{
	D d(3);
	d.B::display();
	d.C::display();
	d.A::display();//即使使用作用域限定符也不能解决
	return 0;
}
