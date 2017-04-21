 ///
 /// @file    vector.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-13 14:39:29
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void printCapacity(vector<int> & vec)
{
	cout << "vec's size = " << vec.size() << endl;
	cout << "vec's capa = " << vec.capacity() << endl;
}

int main(void)
{
	//int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	//vector可以动态扩容 
	//只要当size() == capacity()　时，
	//就直接在原来的capacity()乘以2
	//具体的步骤：
	//1. 先开辟空间
	//2. 再把已有的数据复制到新开辟的空间之中
	//3. 然后再把要添加的新元素存放到新空间中去
	//4. 最后要释放原来的空间
	vector<int> vecInt;
	vecInt.reserve(10);

	printCapacity(vecInt);

	vecInt.push_back(1);
	printCapacity(vecInt);
	vecInt.push_back(2);
	printCapacity(vecInt);
	vecInt.push_back(3);
	printCapacity(vecInt);
	vecInt.push_back(4);
	printCapacity(vecInt);
	vecInt.push_back(5);
	printCapacity(vecInt);
	vecInt.push_back(6);
	printCapacity(vecInt);


	for(size_t idx = 0; idx != vecInt.size(); ++idx)
	{
		cout << vecInt[idx] << " ";
	}
	cout << endl;

	vector<int>::iterator it;
	for(it = vecInt.begin(); it != vecInt.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	for(auto & elem : vecInt)
	{
		cout << elem << " ";
	}
	cout << endl;

	return 0;
}
