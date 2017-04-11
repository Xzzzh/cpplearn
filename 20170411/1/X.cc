 ///
 /// @file    X.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-11 21:57:33
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class X
{
public:
	X(int a)
	: _ix(a)
	, _iy(a)
	{
		cout << "X::X(int)" << endl;
	}

	void print()
	{
		cout << "_ix = " << _ix
			<< ", _iy = " << _iy << endl;
	}
private:
	int _ix;
	int _iy;
};

int main()
{
return 0;
}
