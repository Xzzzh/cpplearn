 ///
 /// @file    pureVirtual.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-04 15:25:02
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//定义了纯虚函数的类称之为抽象类, 不能创建对象
//纯虚函数的实现必须要交给其派生类来实现
class A
{
public:
	//纯虚函数的存在是为了提供一个一致的接口
	virtual void display()=0;
};

//如果一个派生类继承了抽象类，但并没有实现抽象类的纯虚函数，
//则该派生类也会成为抽象类
class B : public A
{
public:
#if 0
	void display()
	{
		cout << "B::display()" << endl;
	}
#endif
};

class C : public B
{
public:
	void display()
	{
		cout << "C::display()" << endl;
	}
};

int main(void)
{
	//A a;//无法创建对象
	A * p = new C;
	p->display();


	return 0;
}
