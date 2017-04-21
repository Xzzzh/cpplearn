 ///
 /// @file    String.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-13 09:44:53
 ///
 
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
	String()
	: _pstr(new char[1])
	{
	}

	String(const char* pstr)
	: _pstr(new char[strlen(pstr) + 1])
	{
		cout << "String(const char *)" << endl;
		strcpy(_pstr, pstr);
	}
					
	String(const String& rhs)
	: _pstr(new char[strlen(rhs._pstr) + 1])
	{
		cout << "String(const String &rhs)" << endl;
		strcpy(_pstr, rhs._pstr);
	}

	String & operator=(const String& rhs)
	{
		if(&rhs == this)
			return *this;
		delete [] _pstr;
		_pstr = new char[strlen(rhs._pstr) + 1];
		strcpy(_pstr, rhs._pstr);
		return *this;
	}

	~String()
	{
		cout << "~String()" << endl;
		delete [] _pstr;
	}

	void print();

private:
	char * _pstr;
};

void String::print(){
	if(_pstr)
		cout <<  _pstr << endl;
}


int main(void)
{
	String str;
	str.print();

	cout << "---" << endl;

	String str2("hello,world");
	String str3 = "wangdao";

	str2.print();
	str3.print();

	return 0;
}
