#ifndef __WD_THREADPOOL_THREAD_H__
#define __WD_THREADPOOL_THREAD_H__

#include "Thread.h"
#include "Threadpool.h"
#include <iostream>

using std::cout;
using std::endl;

namespace wd
{

class ThreadpoolThread
: public Thread
{
public:
	ThreadpoolThread(Threadpool & threadpool)
	: _threadpool(threadpool)
	{}

	void run()
	{
		_threadpool.threadFunc();
	}

	~ThreadpoolThread()
	{
		cout << "~ThreadpoolThread()" << endl;
	}
private:
	Threadpool & _threadpool;

};

}// enf of namespace wd

#endif
