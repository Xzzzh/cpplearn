 ///
 /// @file    abuse_shared_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-02 16:31:53
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;


class Point
: public std::enable_shared_from_this<Point>
{
public:
	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	~Point(){	cout << "~Point()" << endl;	}

	shared_ptr<Point> add(const Point * rhs)
	{
		_ix += rhs->_ix;
		_iy += rhs->_iy;
	
		//return shared_ptr<Point>(this);//在类内部获取指向本对象的智能指针
		return shared_from_this();
	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}


void test0()
{
	shared_ptr<Point> sp1(new Point(1, 2));
	shared_ptr<Point> sp2(new Point(3, 4));

	shared_ptr<Point> sp3(sp2->add(sp1.get()));//sp2所托管的指针又被sp3进行托管了
	cout << "sp3's use_count() = " << sp3.use_count() <<endl;
}



int main(void)
{
	test0();

	return 0;
}
