 ///
 /// @file    sstream.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-13 16:07:34
 ///
 
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::istringstream;
using std::ostringstream;
using std::stringstream;
using std::ifstream;
using std::vector;



void test0()
{
	int ival1 = 512;
	int ival2 = 1024;
	char buff[1024] = {0};

	sprintf(buff, "ival1= %d , ival2= %d\n", ival1, ival2);

	printf("%s\n", buff);
}

void test1()
{
	int ival1 = 512;
	int ival2 = 1024;
	stringstream ss;//sprintf
	ss << "ival1= " << ival1 << " ,ival2= " << ival2;
	string line = ss.str();
	cout << line << endl;

	string word;
	int num;
	while(!ss.eof())
	{
		ss >> word >> num;
		cout << word << ", num = " << num << endl;
	}
}

//将int型数据转换成string
inline string int2str(int num)
{
	ostringstream oss;
	oss << num;
	return oss.str();
}


struct Record
{
Record(const string & key, const string & value)
: _key(key)
, _value(value)
{

}
	string _key;
	string _value;
};

void test2()
{
	ifstream ifs("my.conf");
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return ;
	}

	vector<Record> vec;
	string line;
	string key;
	string value;
	while(getline(ifs, line))
	{
		istringstream iss(line);
		iss >> key >> value;
		vec.push_back(Record(key, value));
	}

	for(auto & elem : vec)
	{
		cout << elem._key << " ---> "  << elem._value << endl; 
	}
}

int main(void)
{
	//test0();
	//test1();
	test2();

	return 0;
}
