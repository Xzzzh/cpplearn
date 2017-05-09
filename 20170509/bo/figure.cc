 ///
 /// @file    figure.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-04 16:02:46
 ///
 
#include <math.h>
#include <iostream>
#include <functional>
using std::cout;
using std::endl;

//基于对象方式进行编程
//std::function + std::bind可以替代虚函数来表现多态,使用时更灵活，选择性更多
//
class Figure
{
	typedef std::function<double()> AreaCallback;
	typedef std::function<void ()> PrintCallback;
public:
	Figure(AreaCallback cb1, PrintCallback cb2)
	: _areaCallback(cb1)
	, _printCallback(cb2)
	{}

	double handleAreaCallback() const
	{
		if(_areaCallback)
			return	_areaCallback();
		else
			return -1;
	}

	void handlePrintCallback() const
	{
		if(_printCallback)
			_printCallback();	
	}

	void setAreaCallback(AreaCallback cb)
	{	_areaCallback = cb;		}

	void setPrintCallback(PrintCallback cb)
	{	_printCallback = cb;	}

private:
	AreaCallback _areaCallback;
	PrintCallback _printCallback;
};


class Circle
{
public:
	Circle(double dRadius)
	: _dRadius(dRadius)
	{}

	double area()
	{
		return kPi * _dRadius * _dRadius;
	}

	void display()
	{
		cout << "Circle";
	}
private:
	static const double kPi;
	double _dRadius;
};

const double Circle::kPi = 3.14159;


class Rectangle
{
public:
	Rectangle(double length, double width)
	: _length(length), _width(width)
	{}
	double calcArea()
	{
		return _length * _width;
	}

	void print()
	{
		cout << "Rectangle";
	}

private:
	double _length;
	double _width;
};

class Triangle
{
public:
	Triangle(double a, double b, double c)
	: _a(a), _b(b), _c(c)
	{}
	double area()
	{
		double p = (_a + _b + _c) / 2;
		return sqrt(p * (p - _a) * (p - _b) * (p - _c));
	}

	void display()
	{
		cout << "Triangel";
	}

private:
	double _a;
	double _b;
	double _c;
};


void display(const Figure & figure)
{
	figure.handlePrintCallback();
	cout << ":"<< figure.handleAreaCallback()<< endl;
}

int main(void)
{
	Circle circle(5);
	Rectangle rectangle(1, 2);
	Triangle triangle(3, 4, 5);

	Figure figure(std::bind(&Circle::area, &circle),
				  std::bind(&Circle::display, &circle));
	display(figure);

	figure.setAreaCallback(std::bind(&Rectangle::calcArea, &rectangle));
	figure.setPrintCallback(std::bind(&Rectangle::print, &rectangle));
	display(figure);

	figure.setAreaCallback(std::bind(&Triangle::area, &triangle));
	figure.setPrintCallback(std::bind(&Triangle::display, &triangle));
	display(figure);

	return 0;
}

