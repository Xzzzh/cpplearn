 ///
 /// @file    shared_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-02 15:23:17
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;


int main(void)
{
	shared_ptr<double> spd(new double(8.88));
	cout << "*spd = " << *spd << endl;
	cout << "spd'get() = " << spd.get() << endl;
	cout << "spd' use_count() = " << spd.use_count() << endl;

	shared_ptr<double> spd2(spd);//能够进行复制和赋值，共享型智能指针
	cout << "*spd2 = " << *spd2 << endl;
	cout << "spd2'get() = " << spd2.get() << endl;
	cout << "spd'get() = " << spd.get() << endl;
	cout << "spd' use_count() = " << spd.use_count() << endl;
	cout << "spd2' use_count() = " << spd2.use_count() << endl;

	return 0;
}
