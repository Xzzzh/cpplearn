 ///
 /// @file    string.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-20 19:59:36
 ///
#include <stdio.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

//std::string 不是线程安全的

int main(void)
{
	string s1;
	cout << "s1 = " << s1 << endl;

	string s2 = "Hello, word! This is a test of g++ strategy of SSO";
	string s3(s2);
	string s4 = s3;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;

	printf("s2's c_str's add = %p\n", s2.c_str());
	printf("s3's c_str's add = %p\n", s3.c_str());
	printf("s4's c_str's add = %p\n", s4.c_str());
	cout << endl;
	
	s1 = s4;
	cout << "after s1 = s4" << endl; 
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	printf("s1's c_str's add = %p\n", s1.c_str());

	cout << "after change s4" << endl;

	s4[0] = 'X';
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;

	printf("s2's c_str's add = %p\n", s2.c_str());
	printf("s3's c_str's add = %p\n", s3.c_str());
	printf("s4's c_str's add = %p\n", s4.c_str());
	cout << endl;

	cout << "after read s3[0]" << endl;
	cout << s3[0] << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1's c_str's add = %p\n", s1.c_str());
	printf("s2's c_str's add = %p\n", s2.c_str());
	printf("s3's c_str's add = %p\n", s3.c_str());

	return 0;


}
