 ///
 /// @file    X.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-13 16:44:14
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class X
{
public:
	X(int a)
	: _ia(a)
	{}

private: //禁止复制   --> 对象语义
	X(const X & rhs);
	X & operator=(const X & rhs);

private:
	int _ia;
};

int main(void)
{
	X x(1);

	X x1 = x;//Error

	return 0;
}
