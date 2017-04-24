 ///
 /// @file    Myqueue.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-24 10:35:03
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template<typename T, int capacity = 20>
class Myqueue
{
public:
	Myqueue();
	~Myqueue();

	bool empty() const;
	bool full() const;
	size_t size() const;
	bool front(T &) const;
	bool rear(T &) const;

	bool enqueue(T &);
	bool outqueue(T &);
private:
	int _front;
	int _rear;
	T * _pq;
};

template<typename T, int capacity>
Myqueue<T, capacity>::Myqueue()
: _front(0)
, _rear(0)
, _pq(new T[capacity])
{
	cout << "queue capacity = " << capacity << endl;
}

template<typename T, int capacity>
Myqueue<T, capacity>::~Myqueue()
{
	delete [] _pq;
	_pq = NULL;
}

template<typename T, int capacity>
bool Myqueue<T, capacity>::empty() const
{
	if (_front == _rear)	
		return true;
	return false;
}

template<typename T, int capacity>
bool Myqueue<T, capacity>::full() const
{
	if ((_rear + 1)%capacity == _front)
		return true;
	return false;
}

template<typename T, int capacity>
size_t Myqueue<T, capacity>::size() const
{
	cout << "rear - front = " << _rear - _front << endl; 
	if (_rear - _front)
		return _rear - _front;
	return	_rear - _front + capacity + 1; 
}

template<typename T, int capacity>
bool Myqueue<T, capacity>::front(T & elem) const
{
	if (empty())
		return false;
	elem = _pq[_front];
	return true;
}

template<typename T, int capacity>
bool Myqueue<T, capacity>::rear(T & elem) const
{
	if (empty())
		return false;
	elem = _pq[_rear - 1];
	return true;
}

template<typename T, int capacity>
bool Myqueue<T, capacity>::enqueue(T & elem)
{
	if (full())
	{
		cout << "que is full" << endl;
		return false;
	}
	_pq[_rear] = elem;
	++_rear;
	return true;
}

template<typename T, int capacity>
bool Myqueue<T, capacity>::outqueue(T & elem)
{

	if (empty())
	{
		cout << "que is empty" << endl;
		return false;
	}
	elem = _pq[_front];
	++_front;
	return true;
}

int main(void)
{
	string s1 = "hello";
	string s2;
	Myqueue<string, 10> que;
	cout << "que.size() = " << que.size() << endl;	
	cout << "is queue empty? " << que.empty() << endl;	
	cout << endl << "ready to enqueue()" << endl;
	for (int i = 0; i < 12; ++i)
	{
		que.enqueue(s1);
	}
	cout << "que.size() = " << que.size() << endl;	
	string s;
	que.front(s);
	cout << "que.front() = " << s << endl;	
	que.rear(s);
	cout << "que.rear() = " << s << endl;	
	cout << endl << "ready to outqueue()" << endl;
	cout << "is queue empty? " << que.empty() << endl;	
	cout << "is queue full? " << que.full() << endl;	
	for (int i = 0; i < 12; ++i)
	{
		if (que.outqueue(s2))
			cout << "elem of que.out() = " << s2 << endl;
		else
			cout << "que.outqueue() failed" << endl;
		
	}
	s = "empty";
	if (que.front(s))
		cout << "que.front() = " << s << endl;	
	else
		cout << "que.front() failed" << endl;
	if (que.rear(s))
		cout << "que.rear() = " << s << endl;	
	else
		cout << "que.rear() failed" << endl;
	return 0;
}
