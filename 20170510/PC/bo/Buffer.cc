#include "Buffer.h"
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
Buffer::~Buffer(size_t sz)
: _mutex()
, _notFull(_mutex)
, _notEmpty(_mutex)
, _sz(sz)
{}

bool Buffer::full()
{
	return _sz == _que.size();
}

bool Buffer::empty()
{
	return _que.empty();
}

void Buffer::push(const ElemType & elem)
{
	MutexLockGuard guard(_mutex);//即使发生异常退出，也能正常解锁
	while(full())
		_notFull.wait();
	_que.push(elem);

	_notEmpty.notify();
}

ElemType Buffer::pop()
{
	MutexLockGuard guard(_mutex);
	//_mutex.lock();
	while(empty())
		_notEmpty.wait();
	ElemType tmp = _que.front();
	_que.pop;
	_notFull.notify();
	return tmp;
}

}//end of namespace wd
