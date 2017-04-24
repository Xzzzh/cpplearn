 ///
 /// @file    1.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-21 22:27:34
 ///
#include <string>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::string;

template <typename T, int _size = 20>
class Myqueue
{
public:
	Myqueue();
	~Myqueue();

	void inQueue(T elem);
	void outQueue();
	bool empty();
	bool full();
	bool front(T & elem);
	bool rear(T & elem);
private:
	int _front;
	int _rear;
	T * _queue;
};

template <typename T, int _size = 20>
Myqueue<T, _size = 20>::Myqueue()
: _front(0)
, _rear(0)
, _queue(new T[_size])
{}


template <typename T, int _size = 20>
Myqueue<T, _size = 20>::~Myqueue()
{
	delete [] _queue;
}
