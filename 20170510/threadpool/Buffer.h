#ifndef __WD_BUFFER_H__
#define __WD_BUFFER_H__

#include "MutexLock.h"
#include "Condition.h"
#include <queue>

using std::queue;

namespace wd
{
class Task;
typedef Task * ElemType;

class Buffer
{
public:
	Buffer(size_t sz);

	bool full();
	bool empty();

	void push(const ElemType & elem);
	ElemType pop();

	void wakeup();
private:
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
	size_t _sz;
	queue<ElemType> _que;
	bool _flag;
};

}//end of namespace wd

#endif
