 ///
 /// @file    ifstream.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-13 15:00:06
 ///
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

using std::ifstream;


int test0(void)
{
	ifstream ifs("iostream.cc");//文件输入流要求文件是存在的
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return -1;
	}

	vector<string> vecStr;
	vecStr.reserve(100);
	string str;
	//while(ifs >> str)// 自动根据空格进行分隔
	while(getline(ifs, str))
	{
		vecStr.push_back(str);
	}

	for(auto & elem : vecStr)
	{
		cout << elem << endl;
	}


	ifs.close();//容易忘记
	return 0;
}

int test1()
{
	ifstream ifs("iostream.cc");
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return -1;
	}

	//ifstream对象不能进行复制 ? 　系统资源在操作的时候要保证只有唯一的对象能够进行操作
	//流对象表达就是对象语义
	//ifstream ifs2 = ifs;//如果能成功，一定会调用复制构造函数

	return 0;
}


int main(void)
{
	test1();

	return 0;
}
