 ///
 /// @file    Computer3.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-11 21:02:59
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
	~Computer()
	{
		cout << "~Computer()" << endl;
		delete [] _brand;	
	}
	void print();
	
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
	Computer com("Macbookpro", 18000);
	com.print();
	return 0;
}
