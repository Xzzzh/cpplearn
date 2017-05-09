 ///
 /// @file    figure.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-04 16:02:46
 ///
 
#include <math.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

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


//工厂模式
//优点: 
//	0. 将复杂对象的初始化过程封装起来，提供一个统一的接口
//	1. 满足单一职责原则:一个工厂类负责一种图形的创建
//	2. 满足开闭原则:如果有新的图形要创建，则只需要扩展一个相应的具体工厂类和
//		一个具体的产品就可以了

class FigureFactory
{
public:
	virtual Figure * create()=0;
};

class CircleFactory : public FigureFactory
{
public:
	Figure * create()
	{
		//Load xml info
		//....
		return new Circle(5);
	}
};

class RectangleFactory : public FigureFactory
{
public:
	Figure * create()
	{
		//Load xml info x , y
		//....
		return new Rectangle(1, 2);
	}
};

class TriangleFactory : public FigureFactory
{
public:
	Figure * create()
	{
		//Load xml info a, b, c
		//.....
		return new Triangle(3, 4, 5);
	}
};

int main(void)
{
	shared_ptr<FigureFactory> fac1(new CircleFactory);
	shared_ptr<Figure> f1(fac1->create());
	display(f1.get());

	shared_ptr<FigureFactory> fac2(new RectangleFactory);
	shared_ptr<Figure> f2(fac2->create());
	display(f2.get());

	shared_ptr<FigureFactory> fac3(new TriangleFactory);
	shared_ptr<Figure> f3(fac3->create());
	display(f3.get());
	return 0;
}
