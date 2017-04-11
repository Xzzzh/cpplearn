 ///
 /// @file    Computer1.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-11 20:41:03
 ///
//#include "Computer.h" //自定义头文件放在C头文件前面
#include <string.h> //C的头文件放在C++头文件前面
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
//class  默认访问权限是private
	public:
	void print()
	{
		cout << "品牌:" << _brand << endl
			 <<	"价格:" << _fPrice << endl;
	}
//	public:
	void setBrand(const char *brand)
	{
		strcpy(_brand, brand);	
	}
//	private:
	void setPrice(float fPrice)
	{
		_fPrice = fPrice;
	}
	private:
	char _brand[20];
	float _fPrice;

};

int main(void)
{
	Computer com;
	com.setBrand("Mac2016");
	com.setPrice(18000);
	com.print();
//	com._fPrice = 5000;
	return 0;
}
