 ///
 /// @file    point1.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-12 19:44:30
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	explicit//禁止编译器自动优化，禁用隐式转换
	Point(int ix, int iy, double & z)
	: _ix(ix)//const数据成员，只能在初始化列表中进行初始化
	, _iy(iy)
	, _ref1(_ix)
	, _ref2(z)//引用数据成员，只能在初始化列表中进行初始化
	{
		cout << "Point(int, int, double &)" << endl;
	}

	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	, _ref1(rhs._ref1)
	, _ref2(rhs._ref2)
	{
		cout << "Point(const Point & rhs)" << endl;
	}
	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << "," << _ref1
			 << "," << _ref2
			 << ")" << endl;
	}
	void setX(int ix)
	{
		_ix = ix;
	}
private:
	int _ix;
	int _iy;
	int & _ref1;//引用数据成员
	double & _ref2;//引用数据成员
};

int main(void)
{
	double z = 5.0;
	Point pt(1, 2, z);
	pt.print();
	
	Point pt2(pt);
	pt2.print();
	cout << "after x changed:" << endl;
	pt.setX(7);//改变_ix的值，也会改变ref1的值
	pt.print();
	pt2.print();

	cout << "after z changed:" << endl;
	z = 6.0;//改变z的值，ref2的值也会改变
	pt.print();
	pt2.print();
}
