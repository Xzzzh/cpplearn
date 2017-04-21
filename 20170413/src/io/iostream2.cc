 ///
 /// @file    iostream2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-13 11:40:38
 ///
 
#include <iostream>
#include <limits>
using std::cin;
using std::cout;
using std::endl;


int main(void)
{
	//Ctrl + d　代表输入结束
	//Ctrl + c  终止程序
	//Ctrl + z  将程序挂起，放到后台运行
	int ival;
	while(cin >> ival, !cin.eof())
	{
		if(cin.bad())
		{
			cout << "IO stream corrupted!" << endl;
			return -1;
		}
		else if(cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "pls input an integer:" << endl;
			continue;
		}

		cout << "ival = " << ival << endl;
	}
	return 0;
}
