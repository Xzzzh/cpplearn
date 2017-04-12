 ///
 /// @file    staticFunc.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-12 20:31:21
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer(const char * brand, float fprice)
	: _brand(new char[strlen(brand) + 1])
	, _fPrice(fprice)
	{
		strcpy(_brand, brand);
		_totalPrice += _fPrice;
	}

	~Computer()
	{
		_totalPrice -= _fPrice;
		delete [] _brand;
	}
	
	static void printTotal()
	{
		cout << "Total price:" << _totalPrice << endl;
	}

	static void print(Computer & com)
	{
		cout << "brand:" << com._brand  << endl;
		cout << "price:" << com._fPrice << endl;
	}

private:
	char * _brand;
	float _fPrice;

	static float _totalPrice;
};

//一个类的静态数据成员由该类的所有对象共享

//静态数据成员必须要在类之外进行初始化
float Computer::_totalPrice = 0.0;


int main(void)
{
	Computer pc1("IBM", 7000);
	Computer::print(pc1);
	cout << "aft buy pc1:";
	Computer::printTotal();//静态成员函数可以直接使用类名调用

	Computer pc2("Mac", 8000);
	Computer::print(pc2);
	cout << "aft buy pc2:";
	Computer::printTotal();//静态成员函数可以直接使用类名调用

	Computer pc3("ASUS", 2000);
	Computer::print(pc3);
	cout << "aft buy pc3:";
	Computer::printTotal();//静态成员函数可以直接使用类名调用

	cout << endl;
	pc2.~Computer();
	cout << "send back pc2:";
	Computer::printTotal();//静态成员函数可以直接使用类名调用
return	0;
}
