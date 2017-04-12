 ///
 /// @file    staticMember.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-12 20:31:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class X
{
public: 
	X(int a)
	: _a(a)
	{}

	void print()
	{
		cout << "X::print() _a = " << _a << endl;
	}
private:
	int _a;
};

class Computer
{
public:
	Computer(float fprice)
	: _fPrice(fprice)
	{
		_totalPrice += _fPrice;
	}

	~Computer()
	{
		_totalPrice -= _fPrice;
	}
	
	void print()
	{
		cout << "total price:" << _totalPrice << endl;
		_x.print();
	}

private:
	float _fPrice;

	static float _totalPrice;

	static X _x;
};

//一个类的静态数据成员由该类的所有对象共享

//静态数据成员必须要在类之外进行初始化
float Computer::_totalPrice = 0.0;

//如果静态数据成员是一个对象，则需要调用相应类型的构造函数进行初始化
X Computer::_x(1);

int main(void)
{
	Computer pc1(7000);
	cout << "aft buy pc1:";
	pc1.print();

	Computer pc2(8000);
	cout << "aft buy pc2:";
	pc2.print();

	Computer pc3(2000);
	cout << "aft buy pc3:";
	pc3.print();

	cout << endl;
	pc2.~Computer();
	cout << "send back pc2:";
	pc2.print();
return	0;
}
