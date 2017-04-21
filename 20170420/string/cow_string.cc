 ///
 /// @file    cow_string.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-20 19:05:08
 ///
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
	//构造函数
	String();
	String(const char *);
	String(const String &);
	//赋值运算符函数
	String & operator=(const String &);
	//析构函数
	~String();
	//返回C类型的常量字符串
	const char * c_str() const
	{
		return _pstr;
	}
	//返回string的size
	size_t size() const
	{
		return strlen(_pstr);
	}
	//重载取下标运算符函数
	char & operator[](size_t);
	//返回引用计数	
	size_t refcount() const
	{
		return _pstr[size() + 1];
	}
private:
	//初始化引用计数
	void initRefCount()
	{
		//size是从1开始(有数据)，而数组下标是从0开始
		_pstr[size() + 1] = 1;
	}
	//引用计数加一
	void increaseRefCount()
	{
		++_pstr[size() + 1];
	}
	//引用计数减一
	void decreaseRefcount()
	{
		--_pstr[size() + 1];
	}
	//重载输出流运算符函数
	friend std::ostream & operator << (std::ostream & os, const String &);
private:
	char * _pstr;
};

std::ostream & operator << (std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}

String::String()
: _pstr(new char[2])
{
	//在'\0'后面加入一个字节用做引用计数
	_pstr[0] = '\0';
	initRefCount();
}

String::String(const char * pstr)
: _pstr(new char[strlen(pstr) + 2])
{
	//strcpy复制时，会把末尾的'\0'也给复制进去，且覆盖一个字符。
	strcpy(_pstr, pstr);
	initRefCount();
}

String::String(const String & rhs)
: _pstr(rhs._pstr)
{
	increaseRefCount();
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
	if (this != &rhs)//不是自身拷贝
	{
		decreaseRefcount();//引用计数先减一
		if(refcount() == 0)//如果减完是0，说明应该删除了
		{
			delete [] _pstr;
			cout << "operator=() ---> delete [] _pstr" << endl;
		}
		_pstr = rhs._pstr;
		increaseRefCount();//先进行指针的变化，再将新的内容的引用计数加一
	}
	return * this;//如果是自身拷贝，直接返回
}

char & String::operator[](size_t idx)//重载下标访问运算符
{
	static char nullchar = '\0';//当下标无效时作为返回值
	//局部static的生存周期是整个进程，但是可见区域不是全局
	if (idx < size())//如果下标取值有效
	{
		if (refcount() > 1)//如果指向的空间有多个引用
		{
			//先申请临时变量，复制一份数据
			char * ptmp = new char[size() + 2];
			strcpy(ptmp, _pstr);
			decreaseRefcount();//引用计数减一
			_pstr = ptmp;//注意引用计数先减一再更改指针
			initRefCount();
		}
		return _pstr[idx];//只有一个引用，不用再开辟空间
	}
	else
		return nullchar;
}

int main(void)
{
	String s1;
	cout << "s1 = " << s1 << endl;
	cout << "s1's refcount() = " << s1.refcount() << endl;

	String s2 = "Hello";
	String s3(s2);
	String s4 = s3;
	cout << "s2 = " << s2 << endl;
	cout << "s2's refcount() = " << s2.refcount() << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s3's refcount() = " << s3.refcount() << endl;
	cout << "s4 = " << s4 << endl;
	cout << "s4's refcount() = " << s4.refcount() << endl;

	printf("s2's c_str's add = %p\n", s2.c_str());
	printf("s3's c_str's add = %p\n", s3.c_str());
	printf("s4's c_str's add = %p\n", s4.c_str());
	cout << endl;
	
	s1 = s4;
	cout << "after s1 = s4" << endl; 
	cout << "s1 = " << s1 << endl;
	cout << "s1's refcount() = " << s1.refcount() << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s2's refcount() = " << s2.refcount() << endl;
	printf("s1's c_str's add = %p\n", s1.c_str());

	cout << "after change s4" << endl;

	s4[0] = 'X';
	cout << "s2 = " << s2 << endl;
	cout << "s2's refcount() = " << s2.refcount() << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s3's refcount() = " << s3.refcount() << endl;
	cout << "s4 = " << s4 << endl;
	cout << "s4's refcount() = " << s4.refcount() << endl;

	printf("s2's c_str's add = %p\n", s2.c_str());
	printf("s3's c_str's add = %p\n", s3.c_str());
	printf("s4's c_str's add = %p\n", s4.c_str());
	cout << endl;

	cout << "after read s3[0]" << endl;
	cout << s3[0] << endl;
	cout << "s1 =" << s1 << endl;
	cout << "s1's refcount() = " << s1.refcount() << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s2's refcount() = " << s2.refcount() << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s3's refcount() = " << s3.refcount() << endl;
	printf("s1's c_str's add = %p\n", s1.c_str());
	printf("s2's c_str's add = %p\n", s2.c_str());
	printf("s3's c_str's add = %p\n", s3.c_str());

	return 0;
}
