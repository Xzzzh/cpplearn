 ///
 /// @file    tempalteQueue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-25 10:15:43
 ///
 
#include <iostream>
using std::cout;
using std::endl;


template <typename T, int SIZE = 10>
class Queue
{
public:
	Queue();
	~Queue();

	bool full();
	bool empty();
	void push(const T & elem);
	void pop();
	T front();
	T back();

private:
	int _front;
	int _rear;
	T * _arr;
};


template <typename T, int SIZE>
Queue<T, SIZE>::Queue()
: _front(0)
, _rear(0)
,_arr(new T[SIZE])
{

}


template <typename T, int SIZE>
Queue<T, SIZE>::~Queue()
{
	delete [] _arr;
}

template <typename T, int SIZE>
bool Queue<T, SIZE>::full()
{
	return _front == (_rear + 1) % SIZE; 
}

template <typename T, int SIZE>
bool Queue<T, SIZE>::empty()
{
	return _front == _rear;
}

template <typename T, int SIZE>
void Queue<T, SIZE>::push(const T & elem)
{
	if(!full())
	{
		_arr[_rear++] = elem;
		_rear %= SIZE;
	}
	else
	{
		cout << "队列已满" << endl;
	}
}

template <typename T, int SIZE>
void Queue<T, SIZE>::pop()
{
	if(!empty())
	{
		++_front;
		_front %= SIZE;
	}
	else
	{
		cout << "队列已空" << endl;
	}
}

template <typename T, int SIZE>
T Queue<T, SIZE>::front()
{
	return _arr[_front];
}

template <typename T, int SIZE>
T Queue<T, SIZE>::back()
{
	return _arr[(_rear - 1 + SIZE) % SIZE];
	//return _arr[_rear - 1];//Error
}


int main(void)
{
	Queue<int> que;
	cout << "此时队列是否为空？" << que.empty() << endl;
	que.push(1);
	cout << "此时队列是否为空？" << que.empty() << endl;

	for(int idx = 2; idx != 12; ++idx)
	{
		que.push(idx);
	}
	cout << "此时队列是否已满?" << que.full() << endl;

	que.pop();
	que.push(10);
	
	cout << "队尾的元素是：" << que.back() << endl;

#if 0
	while(!que.empty())
	{
		cout << que.front() << endl;
		que.pop();
	}

	cout << "此时队列是否为空？" << que.empty() << endl;
#endif
	return 0;

}



