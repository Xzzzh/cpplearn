 ///
 /// @file    bind.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-28 15:48:43
 ///
 
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::bind;


typedef int (*Function)(int,int);//函数指针

int func(int x, int y)
{
	return x + y;
}

int func2(int x, int y)
{
	return x * y;
}

int test0(void)
{
	func(3, 4);

	Function f2 = func;
	cout << "10 + 20 = " << f2(10, 20) << endl;//函数回调

	f2 = func2;
	cout << "10 * 20 = " << f2(10, 20) << endl;//函数回调

	return 0;
}

class A
{
public:
	//非静态成员函数的第一个参数是this指针
	int func(int x, int y)
	{
		cout << "A::func(int,int)" << endl;
		return x + y;
	}

	int data = 10;
};

int test1(void)
{
	std::function<int()> f1 = bind(func, 1, 2);
	cout << "1 + 2 = " << f1() << endl;

	//还可以绑定到成员函数上
	std::function<int()> f2 = bind(&A::func, A(), 1, 2); 
	cout << "f2() = " << f2() << endl;

	A a;
	//对于不提前绑定的参数，要使用占位符_1, _2, _3, _4, ... 占据
	std::function<int(int)> f3 = bind(&A::func, &a, 1, std::placeholders::_1);
	cout << "1 + 10 = " <<  f3(10) << endl;
	return 0;
}


void f(int n1, int n2, int n3, const int & n4, int n5)
{
	cout << "(" << n1
		 << "," << n2
		 << "," << n3
		 << "," << n4
		 << "," << n5 
		 << ")" << endl;
}

int test2(void)
{
	using namespace std::placeholders;
	int n = 7;
	
	//1. 使用bind时，占位符占据的是形参的位置
	//2. 占位符本身的数字代表的是实参传递的位置,
	//可以把占位符理解成是变量，该变量的值是由
	//实参传递过来的，占位符本身的数字是几，就
	//绑定到相应的实参传递时的位置
	//3. 提前绑定参数时，发生的是值传递,直接进行复制
	//4. 实参进行传递时，不限制实参的个数，但是没有
	//跟占位符绑定的实参都是无效参数
	auto f1 = bind(f, _2, _4, 42, std::cref(n), n);
	n = 10;
	f1(1, 2, 1001, 500, 1000, 2000, 300, 1000, 2000, 30000);

	auto f2 = bind(&A::data, A()); 
	cout << "A::data = " << f2() << endl;
	return 0;
}

int main(void)
{
	test1();
	
	//test2();
	return 0;
}
