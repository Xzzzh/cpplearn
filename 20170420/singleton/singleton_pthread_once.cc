 ///
 /// @file    singleton_pthread_once.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-20 22:01:18
 ///
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

//Singleton 第三种实现方法: pthread_once + atexit
//注意编译时要显示连接 -lphtread
class Singleton
{
public:
	static Singleton * getInstance()
	{
		pthread_once(&_once, init);
		return _pInstance;
	}

	static void init()
	{
		_pInstance = new Singleton;
		atexit(destroy);
	}

	static void destroy()
	{
		delete _pInstance;
		_pInstance = NULL;
	}
private:
	Singleton(){cout << "Singleton()" << endl;};	
	~Singleton(){cout << "~Singleton()" << endl;};	
private:
	static Singleton * _pInstance;
	static pthread_once_t _once;
};

Singleton * Singleton::_pInstance = getInstance();
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main(void)
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	cout << "sizeof Singleton: " << sizeof(*p1) << endl;	
	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);

	return 0;
}
