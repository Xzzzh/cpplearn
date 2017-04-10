 ///
 /// @file    string.cc
 /// @author  lemon(sjzxzh@yeah.net)
 /// @date    2017-04-10 20:28:41
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using namespace std;

int main()
{
	string s1;
	string s2 = "c plus plus";
	string s3 = s2;
	string s4 (5, 's');
	//cin >> s1;
	cout << "s2.length() = " << s2.length() << endl;
	cout << s1 << s2 << s3 << s4 << endl;
	string s = "1234567890";
	for (int i = 0, len = s.length(); i < len; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	s[5] = '5';
	cout << s << endl;
	string s6 = s1 + s2;
	string s7 = s + s3;
	

	return 0;
}
