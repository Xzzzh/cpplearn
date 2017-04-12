 ///
 /// @file    NullPointerCall.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-12 21:20:59
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class NullPointer
{
public:
	static void test1();
	void test2();
	void test3(int ix);
	void test4();
private:
	static int _ix;
	int _iy;
};

int NullPointer::_ix = 0;

void NullPointer::test1()
{
	cout << "NullPointer::_ix = " << _ix << endl;
}

void NullPointer::test2()
{
	cout << "very cool!" << endl;
}

void NullPointer::test3(int ix)
{
	cout << "ix = " << ix << endl;
}

void NullPointer::test4()
{
	cout << "iy = " << _iy << endl;
}

int main(void)
{
	NullPointer * p = NULL;
	p->test1();
	p->test2();
	p->test3(2);
	p->test4();

	return 0;
}
