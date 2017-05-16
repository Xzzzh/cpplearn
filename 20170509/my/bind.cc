#include <iostream>
#include <functional>
#include <algorithm>
using std::cout;
using std::endl;
using std::bind;

typedef int (*Function)(int, int);//函数指针

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
	int func(int x, int y)
	{
		cout << "A::func(int, int)" << endl;
		return x + y;
	}

	int data = 10;
};

int test1(void)
{
	std::function<int()> f1 = bind(func, 1, 2);
	cout << "1 + 2 = " << f1() << endl;

	std::function<int()> f2 = bind(&A::func, 1, 2);
	cout << "f2() = " << f2() << endl;

	A a;
	//对于不提前绑定的参数，要使用占位符_1, _2, _3, _4....
	std::function<int(int)> f3 = bind(&A::func, &a, 1, std::placeholders::_1);
	cout << "1 + 10 = " << f3(10) << endl;
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

	//std::cref(argument) 返回一个参数的const 引用
	auto f1 = bind(f, _2, _4, 42, std::cref(n), n);
	n = 10;
	f1(1, 2, 1001, 500, 1000, 2000, 30000, 123123, 23123);

	auto f2 = bind(&A::data, A());
	cout << "A::data = " << f2() << endl;

	return 0;
}

int main(void)
{
	test0(;)

	test1();
	
	test2();
	return 0;
}
