 ///
 /// @file    line.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-12 19:44:30
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	explicit
	Point()
	: _ix(0)
	, _iy(0)
	{
		cout << "Point()" << endl;
	}
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
	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")";
	}
private:
	int _ix;
	int _iy;
};

class Line
{
public:
	Line(int x1, int y1, int x2, int y2)
	: _pt1(x1, y1)//对象成员的初始化，一般也是放在初始化列表中
	, _pt2(x2, y2)
	{
	}

	void printLine()
	{
		_pt1.print();
		cout << "------->";
		_pt2.print();
		cout << endl;
	}
private:
	Point _pt1;
	Point _pt2;
};

int main(void)
{
	Line Line(1, 2, 3, 4);
	Line.printLine();
	return 0;
}
