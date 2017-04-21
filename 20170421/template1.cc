 ///
 /// @file    template1.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-21 20:02:47
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template<typename T1, typename T2>
class Point{
public:
	Point(T1 x, T2 y)
	: _x(x), _y(y){}
public:
	T1 getX() const;
	void setX(T1 x);
	T2 getY() const;
	void setY(T2 y);
private:
	T1 _x;
	T2 _y;
};
