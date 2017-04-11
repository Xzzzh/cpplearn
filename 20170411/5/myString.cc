 ///
 /// @file    myString.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-11 23:53:03
 ///
 
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
			cout << "String::String()"	<< endl;
		}
		String(const char *pstr)
		: _pstr(new char[strlen(pstr) + 1])
		{
			strcpy(_pstr, pstr);	
			cout << "String::String(const char *pstr)"	<< endl;
		}
		String(const String & rhs)
		: _pstr(new char[strlen(rhs._pstr) + 1])
		{
			strcpy(_pstr, rhs._pstr);	
			cout << "String::String(const char *pstr)"	<< endl;
		}
		String & operator=(const String & rhs)
		{
			cout << "String::String & operator=(const String &)" << endl;
			if(this == &rhs)
				return *this;
			delete [] _pstr;
			_pstr = new char [strlen(rhs._pstr) + 1];
			strcpy(_pstr, rhs._pstr);
			return *this;
		}
		~String()
		{
			cout << "String::~String()" << endl;
			delete [] _pstr;
		}

		void print()
		{
			cout << "String::print()" << endl;
			cout << _pstr << endl;
		}

	private:
		char * _pstr;
};

int main(void)
{
		String str1;
		str1.print();
			
		String str2 = "Hello,world";
		String str3 = "wangdao";
					
		str2.print();		
		str3.print();
		str2 = str3;
		str2.print();	
							
		String str4 = str3;
		str4.print();
		return 0;
}
