 ///
 /// @file    struct.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-11 21:54:37
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//struct 的默认访问权限是public
struct A
{
	void print()
	{
		cout << "A::print()" << endl;
	}
//private:
	int _ix;
	int _iy;
};

int main(void)
{
	A a;
	a.print();
	a._ix = 1;
	a._iy = 2;


	return 0;
}
