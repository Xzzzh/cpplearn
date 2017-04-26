 ///
 /// @file    templateSingleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-25 10:52:36
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;


class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix) 
	, _iy(iy)
	{
		cout << "Point()" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}
private:
	int _ix;
	int _iy;
};

template <typename T>
class Singleton
{
	class AutoRelease
	{
	public:
		AutoRelease()
		{
			cout << "AutoRelease()" << endl;
		}

		~AutoRelease()
		{
			if(_pInstance)
			{
				cout << "~AutoRelease()" << endl;
				delete _pInstance;
			}
		}
	};
public:
	static T * getInstance()
	{
		if(_pInstance == NULL)
		{
			_auto;//模板生成时会根据该语句生成一个相应类型的_auto对象
			_pInstance = new T;
		}
		return _pInstance;
	}
private:
	Singleton(){
		cout << "Singleton()" << endl;
	}
	~Singleton(){
		cout << "~Singleton()" << endl;
	}
private:
	static T * _pInstance;
	static AutoRelease _auto;
};

template <typename T>
T * Singleton<T>::_pInstance = getInstance();

//1. 在类内部定义的自定义类型，如果使用模板则必须要使用typename
//告诉编译器这是一个自定义类型，而不是数据成员
//2. 模板的实例化是在实参传递时或者是在函数中要去使用某个对象
template <typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_auto;

int main(void)
{
	Point * pt1 = Singleton<Point>::getInstance();
	Point * pt2 = Singleton<Point>::getInstance();

	printf("pt1 = %p\n", pt1);
	printf("pt2 = %p\n", pt2);

}
