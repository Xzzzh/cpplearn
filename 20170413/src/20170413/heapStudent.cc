 ///
 /// @file    Student.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-13 10:50:31
 ///
 
#include <string.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

//只能生成堆对象：不能生成栈对象的同时还能生成堆对象
//采取的策略是：把析构函数放在private区域

class Student
{
public:
	Student(int id, const char * name)
	: _id(id)
	{
		strcpy(_name, name);
		cout << "Student(int, const char *)" << endl;
	}


	void destroy()
	{
		delete this;
	}

private:
	~Student()
	{
		cout << "~Student()" << endl;
	}

public:
	void print()
	{
		cout << "学号:" << _id << endl;
		cout << "姓名:" << _name << endl;
	}
private:
	int _id;
	char _name[20];
};


int main(void)
{
#if 1
	Student * pstu = new Student(100, "Jackie");//,编译能够通过
	pstu->print();

	pstu->destroy();
	//delete pstu;
#endif

	cout << endl;

	//Student stu(101, "Mike");//Error, 编译无法通过
	//stu.print();

	return 0;
}
