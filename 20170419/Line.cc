 ///
 /// @file    line.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-19 20:01:15
 ///
 
#include "Line.h"
#include <math.h>
#include <iostream>

using std::cout;
using std::endl;

class Line::LineImpl//此类为Line的数据成员,其成员为两个Point对象
{
//private:
	class Point
	{
	public:
		Point(int ix = 0, int iy = 0)
		: _ix(ix)
		, _iy(iy)
		{}

		void print()
		{
			cout << "(" << _ix << "," << _iy << ")";
		}

	private:
		int _ix;
		int _iy;
	};

public:
	LineImpl(int x1, int y1, int x2, int y2)//构造函数
	: _pt1(x1, y1)
	, _pt2(x2, y2)
	{}

	void printLine()//还封装了一个打印显示的方法
	{
		_pt1.print();
		cout << "--->";
		_pt2.print();
	}

private:
	Point _pt1;
	Point _pt2;
};

Line::Line(int x1, int y1, int x2, int y2)
: _pimpl(new LineImpl(x1, y1, x2, y2))
{
	cout << "Line(int, int, int, int)" << endl;
}

Line::~Line()
{
	cout << "~Line()" << endl;
	delete _pimpl;
}

void Line::printLine()
{
	_pimpl->printLine();
}
