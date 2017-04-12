 ///
 /// @file    point3.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-12 21:33:35
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point()
	: _ix(0), _iy(0)
	{
		cout << "Point()" << endl;
	}
	Point(int ix, int iy)
	: _ix(ix)
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

	~Point()
	{
		cout << "~Point()" << endl;
	}

private:
	const int _ix;
	const int _iy;

};

int main(void)
{
	Point arr[5] = {Point(1, 3), Point(3, 6)};

	return 0;
}
