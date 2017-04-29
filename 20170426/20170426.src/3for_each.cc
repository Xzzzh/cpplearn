#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::for_each;

struct Function
{
	void operator()(int number)
	{
		cout << number << " ";
	}
};

int main(void)
{
	vector<int> vec{1, 2, 3, 5, 6};
	vector<int>::iterator it = vec.begin();
	//for_each() 的作用是对同一个容器的两个迭代器之间
	//的所有内容进行Func() 的操作
	for_each(it+1, vec.end()-1, Function());
	cout << endl;
	vector<int> vec2{1, 2, 3, 5, 6};
	it = vec2.end();
	for_each(vec2.begin()+1, it, Function());
	cout << endl;

	return 0;
}
