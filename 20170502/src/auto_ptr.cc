 ///
 /// @file    auto_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-02 14:45:50
 ///
 

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::auto_ptr;


int main(void)
{
	double * ap = new double(7.77);
	auto_ptr<double> apd(ap);
	cout << "*apd = " << *apd << endl;
	cout << "ap = " << ap << endl;
	cout << "apd'get() = " << apd.get() << endl;

	int * p1 = new int(10);
	auto_ptr<int> api(p1);
	auto_ptr<int> api2(api);//进行了复制，表达值语义
							//底层实现是将api托管的指针交给了api2,并把自己的托管的
							//指针的值设置为null,本身是存在缺陷的,现在已经不使用它了

	cout << "*api2 = " << *api2 << endl;
	cout << "*api = " << *api << endl;//Error, Segment fault
	cout << "---" << endl;
	
	return 0;
}
