#include <iostream>
#include <queue>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;

int test0(void)
{
	int arr[10] = {99, 72, 63, 40, 54, 69, 70, 89, 9, 10};
	//优先级队列默认情况下使用的比较函数是小于符号
	//其实现原理：堆排序
	//每一次有新元素添加进来，对顶元素要跟新元素作比较
	//如果满足比较函数，就将新元素替换到对顶元素，原堆顶元素
	//会放到堆底，进行堆调整
	
	priority_queue<int> pq;

	for (size_t idx = 0; idx != 10; ++idx)
	{
		pq.push(arr[idx]);
		cout << "当前队列之中优先级别最高的元素是："
		     << pq.top() << endl;
	}
	cout << endl;

	return 0;
}

int test1(void)
{
	int arr[10] = {99, 72, 63, 40, 54, 69, 70, 89, 9, 10};
	//优先级队列指定比较函数是大于符号
	//其实现原理：堆排序
	//每一次有新元素添加进来，对顶元素要跟新元素作比较
	//如果满足比较函数，就将新元素替换到对顶元素，原堆顶元素
	//会放到堆底，进行堆调整
	
	priority_queue<int> pq;

	for (size_t idx = 0; idx != 10; ++idx)
	{
		pq.push(arr[idx]);
		cout << "当前队列之中优先级别最高的元素是："
		     << pq.top() << endl;
	}

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

	return 0;
}

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
	friend bool operator>(const Point & lhs, const Point & rhs);
	friend struct PointCompare;
private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
		<< "," << rhs._iy
		<< ")";
	return os;
}

bool operator>(const Point & lhs, const Point & rhs)
{
	return lhs._ix > rhs._ix;
}

struct PointCompare
{
	bool operator()(const Point & lhs, const Point & rhs)
	{
		return lhs._ix > rhs._ix;
	}
};

int main(void)
{
	Point pt(1, 1);

	vector<Point> vec{
		Point(9, 1),
		Point(-1, 2),
		Point(3, 7),
		Point(-5, 1),
		Point(0, 1)
	};
	priority_queue<Point, vector<Point>, std::greater<Point> > pq;
//	priority_queue<Point, vector<Point>, PointCompare> pq;
	for (size_t idx = 0; idx != 5; ++idx)
	{
		pq.push(vec[idx]);
		cout << "当前队列中优先级最高的元素是：" << pq.top() << endl;
	}
	while(!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	return 0;
}

