#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;

int main(void)
{
	vector<int> vec;
	cout << "vec's size = " << vec.size() << endl;
	cout << "vec's cap = " << vec.capacity() << endl;

	istream_iterator<int> isi(cin);

	//因为一开始的时候vec是空的，vec.begin()不能获得有效迭代器
	//std::copy(isi, istream_iterator<int>(), vec.begin());
	
	//输入结束以非字符作为标记？
	//istream_iterator<int>() 是输入流迭代器获取末尾位置迭代器的特定用法
	std::copy(isi, istream_iterator<int>(), std::back_inserter(vec));

	//输入流迭代器用的会多一些
	ostream_iterator<int> osi(cout, ".");

	std::copy(vec.begin(), vec.end(), osi);

	return 0;
}

