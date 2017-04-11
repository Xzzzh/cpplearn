 ///
 /// @file    point.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-11 22:14:09
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
//在类内部实现的成员函数， 都是inline函数
public:
	explicit//禁用隐式转换
//有参构造函数
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int, int)" << endl;
//		_ix = ix;
//		_iy = iy;
	}
	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point & rhs)" << endl;	
	}
#if 1
	Point & operator = (const Point & rhs)

	{
		cout << "Point & operator=(const Point & rhs)" << endl;
		this->_ix = rhs._ix;
		this->_iy = rhs._iy;
		return *this;
	}
#endif
	void print(/* Point * const this */)
	{
		//this = 0x0001;//Error
		cout << "(" << _ix
			<< "," << _iy
			<< ")" << endl;
	}
	~Point()
	{
		cout << "~Point()" << endl;
	}
private:
	int _ix;
	int _iy;
};
//当形参是对象，实参与形参进行结合时，也会调用复制构造函数
//因为值传递，就会进行复制
void func(Point x)
{
	x.print();
}
//当函数的返回值是对象， 函数调用完成返回时也会调用复制构造函数
//g++编译器有优化操作，使用编译选项 -fno-elide-constructors
//可以没有经过优化看清具体情况
	//析构函数，如果没有显式定义析构函数，系统也会自动提供一个析构函数
Point func2()
{
	Point pt(1, 2);
	pt.print();
	return pt;
}


int test0(void)
{
	Point pt;
	pt.print();
	Point pt2(1, 2);
	pt2.print();
	cout << endl << endl;

	Point pt3 = pt2;
	pt3.print();
	return 0;
}
int test1(void)
{
	Point pt(1, 2);
	func(pt);
	return 0;
}
int main(void)
{
	Point pt(1, 2);
	Point pt2(3, 4);
	pt = pt2;
	pt.print();
	return 0;
}
