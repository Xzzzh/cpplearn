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


//简单工厂模式
//优点: 将复杂对象的初始化过程封装起来，提供一个统一的接口
//缺点: 
//	1. 不满足单一职责原则:一个工厂类负责所有图形的创建
//	2. 不满足开闭原则:如果有新的图形要创建，则必须要修改FigureFactory
class FigureFactory
{
public:
	static Figure * createCircle()
	{
		//Load xml info
		//....
		return new Circle(5);
	}

	static Figure * createRectangle()
	{
		//Load xml info x , y
		//....
		return new Rectangle(1, 2);
	}

	static Figure * createTriangle()
	{
		//Load xml info a, b, c
		//.....
		return new Triangle(3, 4, 5);
	}
};

#if 0
int test0(void)
{
//问题:每一次创建一个对象时，要有很多初始化的工作要做，
//没有很直接创建对象的过程
	//Load xml info
	//....
	//....
	Circle circle(5);
	display(&circle);

	return 0;
}


int test1()
{
	//Load xml info x , y
	//....
	Rectangle rectangle(3, 4);
	display(&rectangle);

	return 0;
}

int test2()
{
	//Load xml info a, b, c
	//.....
	Triangle triangle(3, 4, 5);
	display(&triangle);
	return 0;
}
#endif

int main(void)
{
	Figure * f1 = FigureFactory::createCircle();
	display(f1);

	Figure * f2 = FigureFactory::createRectangle();
	display(f2);

	Figure * f3 = FigureFactory::createTriangle();
	display(f3);

	return 0;
}
