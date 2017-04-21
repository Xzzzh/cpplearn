 ///
 /// @file    cow.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-20 14:44:23
 ///
 
#include <stdio.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main(void)
{
	string s1 = "Hello, worldsdfadfadsfsafasdfasdf:";
	string s2 = s1;
	string s3 = s1;
	cout << "s1 = :" << s1 << endl;
	cout << "s2 = :" << s2 << endl;
	cout << "s3 = :" << s3 << endl;

	printf("%p\n", s1.c_str());
	printf("%p\n", s2.c_str());
	printf("%p\n", s3.c_str());
	return 0;
}



