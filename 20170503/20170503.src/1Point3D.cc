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
	{ return _ix; }

	int getY() const
	{ return _iy; }

	void display() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}
private:
	int _ix;
protected:
	int _iy;
};

class Point3D
: public Point
{
public:
	Point3D(int ix, int iy, int iz)
	: Point(ix, iy)
	, _iz(iz)
	{}

	void print() const
	{
		cout << "(" << getX()
			 << "," << _iy
			 << "," << _iz
			 << ")" << endl;
	}
private:
	int _iz;
};

class Point4D
: public Point3D
{
private:
	int _iq;		
};

int main(void)
{
	Point3D pt1(3, 4, 5);
	pt1.display();
	pt1.getX();
	pt1.getY();

	Point pt2(1, 2);
//	pt2._iy = 10;

	return 0;
}
