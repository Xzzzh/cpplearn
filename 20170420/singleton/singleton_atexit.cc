 ///
 /// @file    singleton_atexit.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-20 21:43:13
 ///
 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

//Singleton 第二种实现: 恶汉式 + atexit注册
class Singleton
{
public:
	static Singleton * getInstance()
	{
		if (_pInstance == NULL)
		{
			_pInstance = new Singleton;
			atexit(destroy);
			atexit(destroy);
		}
		return _pInstance;
	}

	static void destroy()
	{
		cout << "destroy()" << endl;
		delete _pInstance;//当 delete 一个类的指针时，如果指针不为NULL，则会
		//调用该类的析构函数，如果指针为NULL则不会
		_pInstance = NULL;
	}
private:
	Singleton(){cout << "Singleton()" << endl;}
	~Singleton(){cout << "~Singleton()" << endl;}
private:
	static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = getInstance();

int main(void)
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();

	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);

	return 0;
}
