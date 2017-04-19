 ///
 /// @file    Singleton.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-19 19:52:03
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

//目标：自动回收Singleton对象,利用析构函数能被自动调用的特点
//能够自动调用析构函数的对象类型有：栈对象、全局对象、静态对象

class Singleton
{
private:
	class AutoRelease
	{
	public:
		AutoRelease()
		{
			cout << "AutoRelease()" << endl;
		}

		~AutoRelease()//其实是想用析构函数
		{
			cout << "Singleton::~AutoRelease()" << endl;
			if (_pInstance)//若_pInstance 不为NULL, 删除其指向的空间
				delete _pInstance;
		}
	};

public:
	static Singleton * getInstance()
	{
		if (NULL == _pInstance)//在多线程环境下并不是线程安全的
			_pInstance = new Singleton;
		return _pInstance;
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
	static Singleton * _pInstance;
	static AutoRelease _autoRelease;//static 类型变量在其生命周期结束后会自动释放
};
#if 1
//懒汉式
int s = printf("Lazy mode\n");
Singleton * Singleton::_pInstance = NULL;
#endif

#if 0
//饿汉式
int s = printf("Hungry mode\n");
Singleton * Singleton::_pInstance = getInstance();
#endif
Singleton::AutoRelease Singleton::_autoRelease;

int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	printf("p1 = %p\n", p1);
	printf("p1 = %p\n", p2);

//	Singleton::destroy();//无需手动调用

	return 0;
}
