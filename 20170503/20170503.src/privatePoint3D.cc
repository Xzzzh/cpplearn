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

	int getY() const  //如果派生类采用private继承，则基类public成员在派生类内部具有private权限
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
	int _iy;//在派生类Point3D内是具有private权限
};


class Point3D 
: private Point
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
: public Point3D// _iy在Point4D内部不能进行访问
{
public:
	void display()
	{
		print();
		cout << _iy;
	}


private:
	int _iq;
};

int main(void)
{
	Point3D pt1(3, 4, 5);
	pt1.display();
	pt1.getX();//对于派生类对象而言，派生类private继承自基类时，基类所有成员都不能直接访问
	pt1.getY();
	//pt1._iy;//Error

	return 0;
}
