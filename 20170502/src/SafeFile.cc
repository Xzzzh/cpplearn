 ///
 /// @file    SafeFile.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-02 11:23:10
 ///
 
#include <stdio.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;


//RAII技术实质是：利用栈对象管理资源
class SafeFile
{
public:
	SafeFile(const string & filename)
	: _fp(::fopen(filename.c_str(), "rw+"))
	{
		if(!_fp)
		{
			cout << "fopen file " << filename << " error!" << endl;
		}
	}

	SafeFile(FILE * fp)
	: _fp(fp)
	{
		
	}

	void write(const string & msg)
	{	
		fwrite(msg.c_str(), 1, msg.size(), _fp);
	}

	~SafeFile()
	{
		if(_fp)
		{
			fclose(_fp);
			cout << "fclose(fp)" << endl;
		}
	}
private:
	SafeFile(const SafeFile & rhs);
	SafeFile & operator=(const SafeFile & rhs);
private:
	FILE * _fp;
};

int main(void)
{
	SafeFile sf("test.dat");

	sf.write("hello,wangdao");

	return 0;
}

