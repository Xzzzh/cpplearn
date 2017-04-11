 ///
 /// @file    memory.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-11 20:07:23
 ///
 
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

int a = 0;
char *p1;

int main(void)
{
	int b;
	char s[] = "123456";//s数组在栈空间
	char *p2;
	char *p3 = "123456";//p3本身在栈空间，指向的是文字常量区的字符串
	static int c = 0;
	p1 = new char[10];
	p2 = new char[5];
	strcpy(p1, "123456");

	printf("&a = %p\n", &a);
	printf("p1 = %p\n", p1);
	printf("&p1 = %p\n", &p1);
	printf("p2 = %p\n", p2);
	printf("&p2 = %p\n", &p2);
	printf("&b = %p\n", &b);
	printf("p3 = %p\n", p3);
	printf("s = %p\n", s);
	printf("&c = %p\n", &c);
	
	*p3 = 'X';
	printf("-----\n");
	return 0;
}
