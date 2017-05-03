 ///
 /// @file    String.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-02 09:45:30
 ///
 
#include <string.h>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


class String
{
public:
	String()
	: _pstr(new char[1])
	{
		cout << "String()" << endl;
		_pstr[0] = '\0';
	}

	String(const char * pstr)
	: _pstr(new char[strlen(pstr) + 1])
	{
		cout << "String(const char *)" << endl;
		strcpy(_pstr, pstr);
	}

	//移动构造函数
	String(String && rhs)//右值引用只能绑定到右值
	: _pstr(rhs._pstr) 
	{
		cout << "String(String && rhs)" << endl;
		rhs._pstr = NULL;
	}

	//复制构造函数
	String(const String & rhs) //形参const引用能绑定到左值或者右值上，
							   //意味着它不能区分出传递过来的实参是
							   //左值还是右值；为了达到转移临时对象的内容，
							   //需要新的语法规则能在语法层面识别出右值,
							   //所以C++11中引入了右值引用,右值引用只能绑定到右值
	: _pstr(new char[strlen(rhs._pstr) + 1])
	{
		cout << "String(const String&)" << endl;
		strcpy(_pstr, rhs._pstr);
	}


	//移动赋值运算符　
	String & operator=(String && rhs)
	{
		cout << "String & operator=(String && rhs)" << endl;
		if(this != & rhs)
		{
			delete [] _pstr;
			_pstr = rhs._pstr;

			rhs._pstr = NULL;
		}
		return *this;
	}

	String & operator=(const String & rhs)
	{
		if(this != &rhs)
		{
			delete [] _pstr;

			_pstr = new char[strlen(rhs._pstr) + 1];
			strcpy(_pstr, rhs._pstr);
		}
		return *this;
	}

	~String()
	{
		cout << "~String()" << endl;
		delete [] _pstr;
	}

	friend std::ostream & operator<<(std::ostream & os, const String & rhs);
private:
	char * _pstr;
};

std::ostream & operator<<(std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}

#if 0
String && func()
{
		
}

int & func2()
{
	
}
#endif

int test0(void)
{
	//String && ref = func();
	vector<String> vec;
	vec.push_back("wangdao");

	String("wangdao");//匿名对象，临时对象



	int a = 10;

	int & ref = a;
	//int & ref2 = 10;//非const引用不能绑定到右值
	const int & ref3 = 10;//const引用是可以绑定到右值的

	const int & ref4 = a;//const引用也能绑定到左值



	return 0;
}

void test1()
{
	int && ref = 10;//右值引用只能绑定到右值

	cout << "ref = " << ref << endl;

	int a = 20;
	//int && ref2 = a;//右值引用不能绑定到左值
}


int test2(void)
{
	vector<String> vec;
	vec.push_back("wangdao");

	return 0;
}

int test3(void)
{
	String s1("hello");
	cout << "s1 = " << s1 << endl;

	s1 = String("world");
	cout << "s1 = " << s1 << endl;
	


	return 0;
}

int main(void)
{
	test3();

	return 0;
}
