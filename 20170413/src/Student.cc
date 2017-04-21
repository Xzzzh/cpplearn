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


class Student
{
public:
	Student(int id, const char * name)
	: _id(id)
	{
		strcpy(_name, name);
		cout << "Student(int, const char *)" << endl;
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

	void * operator new(size_t sz)
	{
		cout << "void * operator new(size_t)" << endl;
		void * p = malloc(sz);
		return p;
	}

	void operator delete(void * p)
	{
		cout << "void operator delete(void*) " << endl;
		free(p);
	}

private:
	int _id;
	char _name[20];
};


int main(void)
{
#if 0
	Student * pstu = new Student(100, "Jackie");
	pstu->print();

	delete pstu;
#endif

	cout << endl;

	//如果想创建一个栈对象，相应的构造函数和析构函数都需要放在public区域
	Student stu(101, "Mike");
	stu.print();

	return 0;
}
