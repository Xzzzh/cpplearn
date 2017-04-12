 ///
 /// @file    Singleton.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-12 21:40:57
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

/*单例设计模式*/

//要求：在内存中只能创建该类的一个对象
//1.该对象不能是全局对象或者栈对象
//2.只能是堆对象
//作用
//在一定程度上，取代全局变量

class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(_pInstance == NULL)
		{
			_pInstance = new Singleton;
		}
		return _pInstance;
	}

	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}

private:
	Singleton()
	{
		cout << "Singleton()" << endl;
	}
	~Singleton()
	{
		cout << "~Singleton()" << endl;
	}

private:
	static Singleton * _pInstance;//实例指针
};

Singleton * Singleton::_pInstance = NULL;

int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	Singleton * p3 = Singleton::getInstance();
	
	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);
	printf("p3 = %p\n", p3);

	Singleton::destroy();
	return 0;
}
