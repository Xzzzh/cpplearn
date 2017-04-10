 ///
 /// @file    1.cc
 /// @author  lemon(sjzxzh@yeah.net)
 /// @date    2017-04-10 14:56:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;
#if 0
void swap(int *px, int *py)//值传递， 进行复制
{
	int temp = *px;
	*px = *py;
	*py = temp;
}
#endif

void swap(int & ref1, int & ref2)//引用的底层实现还是指针
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int main(void)
{
	int a = 10;
	int b = 20;
	cout << " a = " << a << endl;
	cout << " b = " << b << endl;
	swap(a, b);
	cout << " a = " << a << endl;
	cout << " b = " << b << endl;
	return 0;
}
