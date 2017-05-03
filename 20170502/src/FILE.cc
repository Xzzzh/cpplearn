 ///
 /// @file    FILE.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-02 16:59:35
 ///
 
#include <stdio.h>
#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;
using std::shared_ptr;


struct Fpcloser
{
	void operator()(FILE * fp)
	{
		if(fp)
		{
			cout << "fclose(fp)" << endl;
			fclose(fp);
		}
	}
};

//对于文件指针这样的回收方式比较特殊的，就需要指定自定义的删除器(函数对象)
int test0(void)
{
	unique_ptr<FILE, Fpcloser> up(fopen("test.dat", "rw+"), Fpcloser());
	
	string msg = "hello,world";
	fwrite(msg.c_str(), 1, msg.size(), up.get());

	return 0;
}

void test1()
{
	shared_ptr<FILE> sp(fopen("test.dat", "rw+"), Fpcloser());
	string msg = "hello,world";
	fwrite(msg.c_str(), 1, msg.size(), sp.get());
}

int main(void)
{
	test1();

	return 0;
}
