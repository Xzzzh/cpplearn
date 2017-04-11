 ///
 /// @file    Computer2.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-11 20:53:01
 ///
#include "Computer.h" 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

void Computer::print()
{
	cout << "Brand:" << _brand << endl
		 << "Price:" << _fPrice << endl;
}

void Computer::setBrand(const char *brand)
{
	strcpy(_brand, brand);
}

void Computer::setPrice(float fPrice)
{
	_fPrice = fPrice;
}
