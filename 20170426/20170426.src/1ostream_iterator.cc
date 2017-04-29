#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

//本例使用一个输出流迭代器，
//并使用copy算法将容器中的两个迭代器之间的内容
//拷贝给输出流迭代器，输出流迭代器与cout绑定
//故屏幕会打印内容
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;

int main(void)
{
	//外部初始化列表
	//这种方式只适用于C++11标准之后
	vector<int> vecInt{1, 2, 3, 4, 5};
	
	//这是一个输出流迭代器
	ostream_iterator<int> osi(cout, " ");

//	不能换成下面的形式
//	auto osi(cout, ",");
//	auto 关键字到底应该怎么用？
//	必须是在接受返回值时使用，才能自行推断

	std::copy(vecInt.begin(), vecInt.end(), osi);

	cout << endl;
	return 0;
}
