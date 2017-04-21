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

//只能生成栈对象：不能生成堆对象的同时还能生成栈对象
//采取的策略是：把operator new/delete放在private区域

class Student
{
public:
	Student(int id, const char * name)
	: _id(id)
	{
		strcpy(_name, name);
		cout << "Student(int, const char *)" << endl;
	}

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
	void * operator new(size_t sz);

	void operator delete(void * p);

private:
	int _id;
	char _name[20];
};


int main(void)
{
#if 0
	Student * pstu = new Student(100, "Jackie");//Error,编译无法通过
	pstu->print();

	delete pstu;
#endif

	cout << endl;

	//如果想创建一个栈对象，相应的构造函数和析构函数都需要放在public区域
	Student stu(101, "Mike");//编译能够通过
	stu.print();

	return 0;
}
