 ///
 /// @file    templateSingleton.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-24 09:59:22
 ///

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class Singleton
{
public:
	static T * getInstance()
	{
		if (NULL == _pInstance)
		{
			_pInstance = new T;
			atexit(destroy);
			cout << "new Singleton Instance" << endl;
		}
		return _pInstance;
	}

	static void destroy()
	{
		cout << "delete Singleton Instance" << endl;
		delete _pInstance;
		_pInstance = NULL;
	}
private:
	Singleton();
	~Singleton();
private:
	static T * _pInstance;
};

class X
{
public:
	X(int x = 0)
	: _x(x)
	{}
	
	void addx()
	{
		++_x;
	}
	void print()
	{
		cout << "_x = :" << _x << endl;
	}
private:
	int _x;
};

template <typename T>
T * Singleton<T>::_pInstance = Singleton<T>::getInstance();

int main(void)
{
	X x = 1;
	x.print();

	cout << "Singleton" << endl;
	X * px1 = Singleton<X>::getInstance();
	X * px2 = Singleton<X>::getInstance();
	px1->print();	
	px2->print();	

	printf("px1 = %p\n", px1);
	printf("px2 = %p\n", px2);
	
	cout << "change" << endl;
	px1->addx();	
	px1->print();	
	px2->print();	

	printf("px1 = %p\n", px1);
	printf("px2 = %p\n", px2);

	return 0;
}
