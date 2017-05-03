 ///
 /// @file    Point3D.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-03 15:49:57
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{}

	int getX() const
	{	return _ix;	}

	int getY() const
	{	return _iy;	}

	void display() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

private://私有成员只能本类内部进行访问
	int _ix;
protected://保护成员只对派生类进行开放
	int _iy;//在派生类Point3D内是具有protected权限
};


class Point3D 
: public Point //接口继承
{
public:
	Point3D(int ix, int iy, int iz)
	: Point(ix, iy)
	, _iz(iz)
	{}
	
	void print() const
	{
		//cout << "(" << _ix//基类私有成员不能在派生类内部直接进行访问
		cout << "(" << getX()//基类私有成员不能在派生类内部直接进行访问
			 << "," << _iy//基类保护成员可以在派生类内部直接进行访问
			 << "," << _iz
			 << ")" << endl;
	}

private:
	int _iz;
};

class Point4D
: public Point3D// _iy在Point4D内部仍然是具有protected权限
{
private:
	int _iq;
};

int main(void)
{
	Point3D pt1(3, 4, 5);
	pt1.display();
	pt1.getX();//对于派生类对象而言，只有派生类公有继承自基类时，只能访问基类的public成员
	pt1.getY();
	//pt1._iy;//Error

	Point pt2(1, 2);
	pt2._iy = 10;

	return 0;
}
