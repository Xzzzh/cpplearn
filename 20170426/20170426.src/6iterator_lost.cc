#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(void)
{
	vector<string> vec;
	vec.push_back("this is A");
	vector<string>::iterator it = vec.begin();
	bool flag = true;
	for(; it != vec.end(); ++it)
	{
		//在遍历数据的过程中，不要添加或者删除数据，可以修改
		//因为添加删除数据会发生动态扩容或减少，底层数据位置发生变化，
		//迭代器会失效
		cout << "vec's size " << vec.size() << endl;
		cout << "vec's cap " << vec.capacity() << endl;
		it = vec.begin();
		cout << "*it = " << *it << endl;
		if (flag)
		{
			vec.push_back("this is B");
			cout << "vec.push_back()" << endl;
			flag = false;
		}
	}
	return 0;
}
