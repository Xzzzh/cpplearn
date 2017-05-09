 ///
 /// @file    multiDerived.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-04 16:35:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class A
{
public:
	virtual void a(){	cout << "A::a()" << endl;	}
	virtual void b(){	cout << "A::b()" << endl;	}
	virtual void c(){	cout << "A::c()" << endl;	}
};

class B
{
public:
	virtual void a(){	cout << "B::a()" << endl;	}
	virtual void b(){	cout << "B::b()" << endl;	}
	void c(){	cout << "B::c()" << endl;	}
	void d(){	cout << "B::d()" << endl;	}
};

class C : public A, public B
{
public:
	virtual void a(){	cout << "C::a()" << endl;	}
	void c(){	cout << "C::c()" << endl;	}
	void d(){	cout << "C::d()" << endl;	}
};

int main(void)
{
	C c;
	A * pa = &c;
	pa->a();
	pa->b();
	pa->c();
	cout << endl;

	B * pb = &c;
	pb->a();
	pb->b();
	pb->c();
	pb->d();
	cout << endl;

	C * pc = &c;
	pc->a();
	//pc->b();//Error,二义性
	pc->c();
	pc->d();
	return 0;
}
