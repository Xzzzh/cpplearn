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
public:
#if 0
	Point()
	{
		cout << "Point()" << endl
	}
#endif
//有参构造函数
#if 1
	Point(int ix = 0, int iy = 0)
	{
		cout << "Point(int, int)" << endl;
		_ix = ix;
		_iy = iy;
	}
#endif
	void print()
	{
		cout << "(" << _ix
			<< "," << _iy
			<< ")" << endl;
	}
	//析构函数，如果没有显式定义析构函数，系统也会自动提供一个析构函数
	~Point()
	{
		cout << "~Point()" << endl;
	}
private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point pt;//调用默认构造函数
	pt.print();

	Point pt2(1, 2);
	pt2.print();

	Point * ppt = new Point(3, 4);
	ppt->print();

	delete ppt;

	return 0;
}
