 ///
 /// @file    2.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-22 10:59:30
 ///
 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class Singleton
{
public:
	static T * getInstance()
	{
		if (_pInstance == NULL)
		{
			cout << "getInstance" << endl;
			_pInstance = new T;
			atexit(destroy);
		}
		return _pInstance;
	}
	static void destroy()
	{

		cout << "destroy" << endl;
		delete _pInstance;
		_pInstance = NULL;
	}
private:
	Singleton(){}
	~Singleton(){}
private:
	static T * _pInstance;
};

template<typename T>
T * Singleton<T>::_pInstance = getInstance();

class X
{};

int main(void)
{
	X * px1 = Singleton<X>::getInstance();
	X * px2 = Singleton<X>::getInstance();
	int *  pi1 = Singleton<int>::getInstance();
	int *  pi2 = Singleton<int>::getInstance();
	printf("px1 = %p\n", px1);
	printf("px2 = %p\n", px2);
	printf("pi1 = %p\n", pi1);
	printf("pi2 = %p\n", pi2);

	return 0;

}
