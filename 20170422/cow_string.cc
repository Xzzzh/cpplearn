 ///
 /// @file    cow_string.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-24 22:23:48
 ///
 
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class String
{
private:
	//代理类
	class CharProxy
	{
	public:
		CharProxy(String &, int);
		CharProxy operator=(char);//写操作

		//读操作
		operator char()
		{
			cout << "operator char()" << endl;
			return _str._pstr[_idx];
		}
//		friend std::ostream & operator<<(std::ostream & os, const CharProxy & rhs);
	private:
		String & _str;
		int _idx;
	};

public:
	String();
	~String();
	String(const char *);
	String(const String &);
	String & operator=(const String &);

	size_t size() const
	{
		return strlen(_pstr);	
	}
	size_t refcount() const
	{
		return _pstr[size() + 1];
	}
	const char * c_str() const
	{
		return _pstr;
	}
	CharProxy operator[](int);
private:
	void initRefcount()
	{
		_pstr[size() + 1] = 1;
	}
	void increaseRefcount()
	{
		++_pstr[size() + 1];
	}
	void decreaseRefcount()
	{
		--_pstr[size() + 1];
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

String::String()
: _pstr(new char[2])
{
	_pstr[0] = '\0';
	initRefcount();
}

String::String(const char * pstr)
: _pstr(new char[strlen(pstr) + 2])
{
	strcpy(_pstr, _pstr);
	initRefcount();
}

String::String(const String & rhs)
: _pstr(rhs._pstr)
{
	increaseRefcount();
}

String::~String()
{
	decreaseRefcount();
	if(refcount() == 0)
	{
		delete [] _pstr;
		cout << "delete [] _pstr" << endl;
	}
}

String & String::operator=(const String & rhs)
{
	if(this != &rhs)
	{
		decreaseRefcount();
		if(refcount() == 0)
		{
			delete [] _pstr;
			cout << "operator=()--->delete [] _pstr" << endl;
		}
		_pstr = rhs._pstr;
		increaseRefcount();
	}
	return * this;
}

String::CharProxy String::CharProxy::operator=(char ch)
{
	if(_idx >= 0 && _idx < (int)_str.size())
	{
		if(_str.refcount() > 1)
		{
			char * ptmp = new char[_str.size() + 2];
			strcpy(ptmp, _str.c_str());
			_str.decreaseRefcount();
			_str._pstr = ptmp;
			_str.initRefcount();
		}
		_str._pstr[_idx] = ch;
	}
	return * this;
}

String::CharProxy::CharProxy(String & str, int idx)
: _str(str)
, _idx(idx)
{}

String::CharProxy String::operator[](int idx)
{
	return CharProxy(* this, idx);
}

#if 0
char & String::operator[](int idx)
{
	static char nullchar = '\0';
	if(idx >= 0 && idx < (int)size())
	{
		if(refcount() > 1)
		{
			char * ptmp = new char[size() + 2];
			strcpy(ptmp, _pstr);

			decreaseRefcount();
			_pstr = ptmp;
			initRefcount();
		}
		return _pstr[idx];
	}
	else
		return nullchar;
}

#endif


int main(void)
{
	//const char * p = "hello,world";//C风格的字符串类型
	//char str[] = "hello,world";//字符数组
	//int arr[] = {1, 2, 3, 4, 5};
	String s1;
	cout << "s1 = " << s1 << endl;
	cout << "s1's refcount() = " << s1.refcount() << endl;

	String s2 = "hello";
	String s3(s2);
	String s4 = s3;
	cout << "s2 = " << s2 << endl;
	cout << "s2's refcount() = " << s2.refcount() << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s3's refcount() = " << s3.refcount() << endl;
	cout << "s4 = " << s4 << endl;
	cout << "s4's refcount() = " << s4.refcount() << endl;

	printf("s2's c_str's address = %p\n", s2.c_str());
	printf("s3's c_str's address = %p\n", s3.c_str());
	printf("s4's c_str's address = %p\n", s4.c_str());
	cout << endl;

	s1 = s4;
	cout << "执行完赋值操作之后:" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s1's refcount() = " << s1.refcount() << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s2's refcount() = " << s2.refcount() << endl;
	printf("s1's c_str's address = %p\n", s1.c_str());

	cout << endl << "修改s4字符串之后:" << endl;

	s4[0] = 'X';//做写操作

	cout << "s1 = " << s1 << endl;
	cout << "s1's refcount() = " << s1.refcount() << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s2's refcount() = " << s2.refcount() << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s3's refcount() = " << s3.refcount() << endl;
	cout << "s4 = " << s4 << endl;
	cout << "s4's refcount() = " << s4.refcount() << endl;

	printf("s1's c_str's address = %p\n", s1.c_str());
	printf("s2's c_str's address = %p\n", s2.c_str());
	printf("s3's c_str's address = %p\n", s3.c_str());
	printf("s4's c_str's address = %p\n", s4.c_str());

	cout << endl << "读取字符串s3[0]之后:" << endl;
	cout << s3[0] << endl;//做读操作(按理来说，读操作不应该进行复制)
	cout << "s1 = " << s1 << endl;
	cout << "s1's refcount() = " << s1.refcount() << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s2's refcount() = " << s2.refcount() << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s3's refcount() = " << s3.refcount() << endl;
	printf("s1's c_str's address = %p\n", s1.c_str());
	printf("s2's c_str's address = %p\n", s2.c_str());
	printf("s3's c_str's address = %p\n", s3.c_str());

	return 0;
}
