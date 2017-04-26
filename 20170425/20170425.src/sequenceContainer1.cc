 ///
 /// @file    sequenceContainer1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-25 15:08:57
 ///
 
#include <iostream>
#include <vector>
#include <deque>
#include <list>
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;

int main(void)
{
	//int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	//vector<int> vecInt(arr, arr + 8);
	//vector<int> vecInt{1, 2, 3, 4, 5, 6, 7, 8};//C++11
	vector<int> vecInt = {1, 2, 3, 4, 5, 6, 7, 8};


	//迭代器的区间是一个左闭右开的区间:  [ )
	vector<int>::iterator it = vecInt.begin();
	for(; it != vecInt.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	cout << "双端队列：" << endl; 
	deque<int> dq{1, 2, 3, 4, 5, 6};
	for(size_t idx = 0; idx != dq.size(); ++idx)
	{
		cout << dq[idx] << " ";
	}
	cout << endl;

	//list不支持随机访问,没有重载下标访问运算符
	list<int> listInt{1, 2, 3, 4, 5, 6};
	for(size_t idx = 0; idx != listInt.size(); ++idx)
	{
		cout << listInt[idx] << " ";
	}
	cout << endl;

	
	return 0;
}
