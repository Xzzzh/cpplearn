 ///
 /// @file    Computer4.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-11 21:17:37
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
	public:
		Computer(const char * brand, float fPrice)
		: _brand(new char[strlen(brand) + 1])
		, _fPrice(fPrice)
		{
			cout << "Computer(const char *, float)" << endl;
			strcpy(_brand, brand);
		}
		void print();
//系统提供的复制构造函数
#if 0
Computer(const Computer & rhs)
: _brand(rhs._brand)//浅拷贝
, _fPrice(rhs._fPrice)
{
	cout << "Computer(const Computer &)" << endl;
}
#endif

	Computer(const Computer & rhs)
	: _brand(new char[strlen(rhs._brand) + 1])//深拷贝
	, _fPrice(rhs._fPrice)
	{
		strcpy(_brand, rhs._brand);
		cout << "Computer(const Computer &)" << endl;
	}
	~Computer()
	{
		cout << "~Computer()" << endl;
		delete [] _brand;
	}
private:
	char * _brand;
	float _fPrice;
};

void Computer::print()
{
	cout << "Brand:" << _brand << endl
		 << "Price:" << _fPrice << endl;
}

int main(void)
{
	Computer com("MBP2016", 18000);
	com.print();
//	com.~Computer();//析构函数可以显式调用，但一般不这样
	Computer com2 = com;
	com2.print();

	//Computer & com3 =  Computer("IBM", 7000);
#if 0
	int a = 10;
	int & ref = a;
	const int & ref1 = 10;//10叫右值，不能取地址
#endif
	return 0;
}
