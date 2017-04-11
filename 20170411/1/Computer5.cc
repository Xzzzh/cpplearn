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
//复制构造函数的参数不能是对象，如果是，就会产生无情递归
//使用引用就可以打破无穷递归
//const关键字不能去掉， 非const引用不能绑定到右值

	Computer(const Computer & rhs)
	: _brand(new char[strlen(rhs._brand) + 1])//深拷贝
	, _fPrice(rhs._fPrice)
	{
		strcpy(_brand, rhs._brand);
		cout << "Computer(const Computer &)" << endl;
	}
#if 1
	Computer & operator=(const Computer & rhs)
	{
		cout << "Computer & operator=(const Computer)" << endl;
		if (this == &rhs)
			return *this;
		delete [] _brand;

		_brand = new char[strlen(rhs._brand) + 1];
		strcpy(_brand, rhs._brand);

		this->_fPrice = rhs._fPrice;
		return *this;
	}
#endif

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
	Computer com2("IBM", 8000);
	com2.print();

	cout << "after = " << endl;
	com2 = com;
	com2.print();
	com = com;
	//Computer & com3 =  Computer("IBM", 7000);
#if 0
	int a = 10;
	int & ref = a;
	const int & ref1 = 10;//10叫右值，不能取地址
#endif
	return 0;
}
