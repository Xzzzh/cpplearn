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
	explicit
	Point(int ix = 0, int iy = 0)
	: _ix(ix)//const数据成员，只能在初始化列表中进行初始化
	, _iy(iy)
	{
		cout << "Point(int, int)" << endl;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}
private:
	const int _ix;
	const int _iy;
};

int main(void)
{
	Point pt(1, 2);
	pt.print();
}
