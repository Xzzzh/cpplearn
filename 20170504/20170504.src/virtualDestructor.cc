 ///
 /// @file    virtualDestructor.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-04 16:19:18
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;


class Base
{
public:
	Base()
	: _pdata(new char[64])
	{
		cout << "Base()" << endl;
	}

	virtual
	~Base()
	{
		delete [] _pdata;
		cout << "~Base()" << endl;
	}
private:
	char * _pdata;
};

class Child : public Base
{
public:
	Child()
	: _pdata2(new char[64])
	{
		cout << "Child()" << endl;
	}

	~Child()
	{
		delete [] _pdata2;
		cout << "~Child()" << endl;
	}
private:
	char * _pdata2;
};

int main(void)
{
	Base * p = new Child;
	//unique_ptr<Base> up(p);

	delete p;//需求：通过基类的指针释放派生类对象
			 //--> 通过基类的指针调用派生类的析构函数

	return 0;
}
