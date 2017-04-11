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
//有参构造函数
	Point(int ix = 0, int iy = 0)
	: _ix(ix)//初始化表达式
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
	return 0;
}
