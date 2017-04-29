#include <stdio.h>
#include <iostream>
using namespace std;

//Sift函数完成对数组R在low到high下标之间的，low位置的节点进行堆调整
//这个函数只对low节点的子树进行调整
//非递归算法
//数组下标从1开始！！！

void Sift_greater(int R[], int low, int high)
{//本函数为大顶堆
	int i = low, j = 2*i;//R[j]初始时是R[i]的做孩子
	int temp = R[i];//存储low位置的值以便更改
	while (j <= high)
	{
		//范围边界条件
		if (j < high && R[j] < R[j + 1])
			//当有孩子存在时，选出左、右孩子节点中较大的一个
			++j;
		if (temp < R[j])
		{
			R[i] = R[j];//将R[j]调整到双亲节点位置
			i = j;//修改i和j的值，以便继续向下层走
			j = 2*i;//完全二叉树右孩子存在则左孩子必存在
			//所以只需要先判断左孩子存在
		}
		else
			break;//调整结束
	}
	R[i] = temp;//被调整结点的值放入最终位置
}

void Sift_less(int R[], int low, int high)
{//本函数为小顶堆
	int i = low, j = 2*i;
	int temp = R[i];
	while (j <= high)
	{
		if (j < high && R[j] > R[j+1])
			++j;
		if (temp > R[j])
		{
			R[i] = R[j];
			i = j;
			j = 2*i;
		}
		else
			break;
	}
	R[i] = temp;
}

void heapSort_greater(int R[], int n)
{
	int i;
	int temp;
	for (i = n / 2; i >= 1; --i) //建堆
		Sift_greater(R, i, n);
	for (i = n; i >= 2; --i)//位置调整
	{
		//换出根元素放入最终位置
		temp = R[1];
		R[1] = R[i];
		R[i] = temp;
		Sift_greater(R, 1, i - 1);
	}
}

void heapSort_less(int R[], int n)
{
	int i;
	int temp;
	for (i = n / 2; i >= 1; --i) //建堆
		Sift_less(R, i, n);
	for (i = n; i >= 2; --i)//位置调整
	{
		//换出根元素放入最终位置
		temp = R[1];
		R[1] = R[i];
		R[i] = temp;
		Sift_less(R, 1, i - 1);
	}
}

int main(void)
{
	const int n = 10;
	int R[n+1] = {1001, 3, 2, 9, 4, 1, 5, 11, 18, 7, 10};//注意下标从1开始！！！
	for (int i = 1; i <= 10; ++i)
		cout << R[i] << " ";
	cout << endl;

	heapSort_greater(R, n);
	for (int i = 1; i <= 10; ++i)
		cout << R[i] << " ";
	cout << endl;

	heapSort_less(R, n);
	for (int i = 1; i <= 10; ++i)
		cout << R[i] << " ";
	cout << endl;
	return 0;
}
