 ///
 /// @file    string.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-17 21:56:31
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//实现String类的其他运算符的重载
class String{
public:
	String();
	String(const char *);
	String(const String &);
	~String();

	String & operator=(const char *);
	String & operator=(const String &);

	String & operator+=(const char *);
	String & operator+=(const String &);

	char & operator[](std::size_t index);
	const char & operator[](std::size_t index) const;

	std::size_t size() const;
	const char * c_str() const;

	friend bool operator==(const String &, const String &);
	friend bool operator!=(const String &, const String &);

	friend bool operator<(const String &, const String &);
	friend bool operator>(const String &, const String &);
	friend bool operator<=(const String &, const String &);
	friend bool operator>=(const String &, const String &);
	
	friend std::ostream & operator<<(std::ostream & os, const String & s);
	friend std::istream & operator>>(std::istream & is, String & s);

private:
	char * _pstr;
};

String operator+(const String & lrhs, const String & rrhs)
{
	String tmp;
	tmp += lrhs;
	tmp += rrhs;
	return	tmp;
}

String operator+(const String & rhs, const char * str)
{
	String tmp;
	tmp += rhs;
	tmp += str;
	return	tmp;
}

String operator+(const char * str, const String & rhs)
{
	String tmp;
	tmp += str;
	tmp += rhs;
	return	tmp;
}

String::String()
: _pstr(new char[1]())//注意，new 申请数组时并不会进行初始化
{
	cout << "befor init, _pstr = :" << _pstr << endl;
//	_pstr[0] = '\0';
}

String::String(const char * str)
: _pstr(new char[strlen(str) + 1])
{
	strcpy(_pstr, str);
}

String::String(const String & rhs)
: _pstr(new char[strlen(rhs._pstr) + 1])
{
	strcpy(_pstr, rhs._pstr);
}

String::~String()
{
	delete [] _pstr;
}

String & String::operator=(const char * str)
{
	if (_pstr == str)
		return *this;
	delete [] _pstr;
	_pstr = new char[strlen(str) + 1];
	strcpy(_pstr, str);
	return *this;
}

String & String::operator=(const String & rhs)
{
	if (this == &rhs)
		return *this;
	delete [] _pstr;
	_pstr = new char[strlen(rhs._pstr) + 1];
	strcpy(_pstr, rhs._pstr);
	return *this;
}

String & String::operator+=(const String & rhs)
{
	char * ptmp = new char[strlen(_pstr) + 1];
	strcpy(ptmp, _pstr);
	delete [] _pstr; 
	if (this == &rhs)
	{
		_pstr = new char[strlen(ptmp)*2 + 1];
		strcpy(_pstr, ptmp);
		strcat(_pstr, ptmp);
	}
	else
	{
		_pstr = new char[strlen(ptmp) + strlen(rhs._pstr) + 1];
		strcpy(_pstr, ptmp);
		strcat(_pstr, rhs._pstr);
	}
	delete [] ptmp;
	return *this;
}

String & String::operator+=(const char * str)
{
	char * ptmp = new char[strlen(_pstr) + 1];
	strcpy(ptmp, _pstr);
	delete [] _pstr; 
	if (_pstr == str)
	{
		_pstr = new char[strlen(ptmp)*2 + 1];
		strcpy(_pstr, ptmp);
		strcat(_pstr, ptmp);
	}
	else
	{
		_pstr = new char[strlen(ptmp) + strlen(str) + 1];
		strcpy(_pstr, ptmp);
		strcat(_pstr, str);
	}
	delete [] ptmp;
	return *this;
}

char & String::operator[](std::size_t index)
{
	static char tmp = '\0';
	if(index < strlen(_pstr))
		return _pstr[index];
	else
		return tmp;
}

const char & String::operator[](std::size_t index) const
{
	static char tmp = '\0';
	if(index < strlen(_pstr))
		return _pstr[index];
	else
		return tmp;
}

std::size_t String::size() const
{
	return strlen(_pstr);
}

const char * String::c_str() const
{
	return _pstr;
}

bool operator==(const String & lrhs, const String & rrhs)
{
	if (!strcmp(lrhs._pstr, rrhs._pstr))
		return true;
	else
		return false;
}

bool operator!=(const String & lrhs, const String & rrhs)
{
	return !operator==(lrhs, rrhs);
}

bool operator>(const String & lrhs, const String & rrhs)
{
	if (strcpy(lrhs._pstr, rrhs._pstr) > 0)
		return true;
	else
		return false;
}

bool operator<(const String & lrhs, const String & rrhs)
{
	if (strcpy(lrhs._pstr, rrhs._pstr) < 0)
		return true;
	else
		return false;
}

bool operator>=(const String & lrhs, const String & rrhs)
{
	return !operator<(lrhs, rrhs);
}

bool operator<=(const String & lrhs, const String & rrhs)
{
	return !operator>(lrhs, rrhs);
}

std::ostream & operator<<(std::ostream & os, const String &s)
{
	os << s._pstr;
	return os;
}

std::istream & operator>>(std::istream & is, String &s)
{
	const int String_len_max = 1024*1024*1024;
	int i = 0;
	char * tmp = new char[String_len_max];
	do
	{
		is >> tmp; 
		++i;
	}while(tmp[i] == '\n' || i == String_len_max );
	delete [] s._pstr;
	s._pstr = new char[i + 1];
	strcpy(s._pstr, tmp);
	delete [] tmp;
	return is;
}

int main(void)
{
	String s1 = "qq";
	String s2 = "Hello,world!";
	String s3 = "asdf";
	String s4 = s1 + s2 + s3;
	cout << "s4 = " << s4 << endl;
	cout << s1 + s2 + s3 << endl;
	cout << (s1 + s2 + s3) << endl;
	cout << (s1 + s2) + s3 << endl;
	cout << "s4 = " << s4 << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << s1 + s2 + s3 << endl;
	cout << (s1 + s2 + s3) << endl;
	cout << (s1 + s2) + s3 << endl;
	cout << "s4 = " << s4 << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << s1 + s2 + s3 << endl;
	cout << (s1 + s2 + s3) << endl;
	cout << (s1 + s2) + s3 << endl;
	cout << "s4 = " << s4 << endl;
#if 0	
	cout << "s1 = " << s1 << endl
		<< "s2 = " << s2 << endl
		<< "s3 = " << s3 << endl;
	String s4;
	cin >> s4;
	cout << "s4 = " << s4 << endl;
	String s5 = (s2 + s4);
	cout << "s5 = " << s5 << endl;
	cout << "s5[3] = " << s5[3] << endl;
	cout << "s1+=s2 = " << (s1+=s2) << endl;
	cout << "s1+=endl = " << (s1+="endl") << endl;

	if (s1 > s2)
		cout << "s1 > s2" << endl;
	if (s1 <= s2)
		cout << "s1 <= s2" << endl;
	if (s1 < s2)
		cout << "s1 < s2" << endl;
	if (s1 >= s2)
		cout << "s1 >= s2" << endl;
	cout << "s2 = " << s2 << endl
		<< "s3 = " << s3 << endl;

	if (s2 == s3)
		cout << "s2 == s3" << endl;
	if (s2 != s3)
		cout << "s2 != s3" << endl;
	if (s5 == s3)
		cout << "s5 == s2" << endl;
	if (s5 != s3)
		cout << "s5 != s3" << endl;
#endif
	return 0;
}
