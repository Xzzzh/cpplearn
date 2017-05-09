 ///
 /// @file    figure.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-04 16:02:46
 ///
 
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;



class Figure
{
public:
	virtual double area()=0;
	virtual void display()=0;
};

//对修改关闭，对扩展开放
void display(Figure * fig)
{
	fig->display();
	cout << "的面积:" << fig->area() << endl;
}

class Circle : public Figure
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


class Rectangle : public Figure
{
public:
	Rectangle(double length, double width)
	: _length(length), _width(width)
	{}
	double area()
	{
		return _length * _width;
	}

	void display()
	{
		cout << "Rectangle";
	}

private:
	double _length;
	double _width;
};

class Triangle : public Figure
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

int main(void)
{
	Circle circle(5);
	Rectangle rectangle(3, 4);
	Triangle triangle(3, 4, 5);

	display(&circle);
	display(&rectangle);
	display(&triangle);

	return 0;
}
