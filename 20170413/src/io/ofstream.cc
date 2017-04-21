 ///
 /// @file    ofstream.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-13 15:14:31
 ///
 
#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::fstream;


int test0(void)
{

	ifstream ifs("iostream.cc");
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return -1;
	}
	//文件输出流不需要文件是存在的,
	//1. 如果没有，直接创建一个新文件
	//2. 如果存在，并且里面有内容，它会直接将文件内容清空
	ofstream ofs("test.txt");
	if(!ifs.good())
	{
		cout << "ofstream open error!" << endl;
		ifs.close();
		return -1;
	}

	string line;
	while(getline(ifs, line))
	{
		ofs << line << endl;
	}
	ofs.close();

	ifs.close();

	return 0;
}


int test1()
{
	//ofstream ofs("test.txt", std::ios::ate);
	ofstream ofs("test.txt", std::ios::app);
	if(!ofs.good())
	{
		cout << "ofstream open error!" << endl;
		return -1;
	}
	cout << ofs.tellp() << endl;

	ofs << "that's new"; 

	return 0;
}

int test2()
{
	//ate模式只能针对文件输入流起作用
	ifstream ifs("test.txt", std::ios::ate);
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return -1;
	}
	cout << ifs.tellg() << endl;

	ifs.close();
	return 0;
}

int test3()
{
	//fstream要求文件必须存在
	fstream fs("data.txt", std::ios::in | std::ios::out);
	if(!fs.good())
	{
		cout << "fstream open error!" << endl;
		return -1;
	}

	int ival;
	for(size_t idx = 0; idx != 10; ++idx)
	{
		cin >> ival;
		fs << ival << " ";
	}
	cout << fs.tellp() << endl;

	fs.seekg(0, std::ios::beg);

	cout << fs.tellp() << endl;

	for(size_t idx = 0; idx != 10; ++idx)
	{
		fs >> ival;
		cout << ival << " ";
	}
	cout << endl;
	
	return 0;
}


int main(void)
{
	//test0();
	//test1();
	//test2();
	test3();
}
