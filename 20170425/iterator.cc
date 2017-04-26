#include <vector>
#include <iostream>

using namespace std;
//本程序主要测试当容器大小发生变化后，
//原来的迭代器失效
//原理是因为迭代器类似指针，而容器大小发生变化后，
//存储位置发生变化，再对原迭代器间接访问会造成非法内存访问
//进而发生段错误
//
//所以在容器size发生变化后，迭代器也要重新获取

int main(void)
{
	vector<string> vcs;
	vcs.push_back("this is A");
	vector<string>::iterator it = vcs.begin();
	int i = 9;
	for (; it != vcs.end(); ++it)
	{
		it = vcs.begin();
		cout << "capacity of vector is " << vcs.size() << endl;
		cout << "---->" << *it << endl;
		if(i == 9)
		{
			vcs.push_back("this is bbbb");
			cout << "vcs.push!" << endl;
		}
		i = 8;
		cout << "i = :" << i << endl;
	}
}

