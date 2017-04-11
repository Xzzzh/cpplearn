 ///
 /// @file    Computer.h
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-11 20:32:42
 ///
 
#ifndef __WD_COMPUTER_H__
#define __WD_COMPUTER_H__

class Computer
{
	public://类为外部提供的访问接口
		void print();
	public:
		void setBrand(const char *brand);
		void setPrice(float fPrice);
	private://私有成员只能再类内部进行访问，体现了类的封装性
		char _brand[20];//注意代码风格
		float _fPrice;
};
#endif
