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

int main(void)
{
	String s1("hello");
	cout << "s1 = " << s1 << endl;

	String s2 = std::move(s1);//move函数显示地将左值引用转换成右值引用
	cout << "s2 = " << s2 << endl;

	cout << "s1 = " << s1 << endl;

	return 0;
}
