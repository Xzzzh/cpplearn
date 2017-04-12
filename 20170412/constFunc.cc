 ///
 /// @file    constFunc.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-12 21:02:05
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int, int)" << endl;	
	}

	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point & rhs)" << endl;	
	}
#if 1
	void print(/*const Point * const this*/) const
	{
		cout << "void print()const" << endl;
		//_ix = 10; //Error
		cout << "(" << _ix
			<< "," << _iy
			<< ")" << endl;
	}
#endif

#if 0
	void setX(int ix)
	{
		_ix = ix;
	}

	void print()
	{
		cout << "void print()" << endl;
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}
#endif
private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point pt(1, 2);
	pt.print();//非const 对象可以使用const成员函数

//	const int a = 10;
	const Point pt2(3, 4);//const 对象不能修改器内部数据成员，不能调用非const成员函数
//	只能调用const成员函数

	pt2.print();

	return 0;
}
