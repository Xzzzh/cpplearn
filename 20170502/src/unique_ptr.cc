 ///
 /// @file    unique_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-02 14:59:30
 ///
 
#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;


unique_ptr<int> getValue()
{
	unique_ptr<int> upi(new int(6));
	return upi;
}

int test0(void)
{
	unique_ptr<double> upd(new double(8.88));
	cout << "*upd = " << *upd << endl;
	cout << "upd'get() = " << upd.get() << endl;

	unique_ptr<int> upi(new int(8));
	//unique_ptr<int> upi2(upi);//Error, 不能进行复制或赋值
	
	getValue();

	//unique_ptr<int> upi3 = upi;//Error
	unique_ptr<int> upi3 = std::move(upi);//表达的是移动语义
	cout << "*upi3 = " << *upi3 << endl;
	//cout << "*upi = " << *upi << endl;//Error

	unique_ptr<int> upi4 = getValue();//调用的是移动构造函数
	cout << "*upi4 = " << *upi4 << endl;
	
	return 0;
}


void test1()
{
	unique_ptr<int> upi(new int(6));//是命名对象，左值
	vector<unique_ptr<int> > vec;
	vec.push_back(std::move(upi));
}

int main(void)
{
	test1();

	return 0;
}
