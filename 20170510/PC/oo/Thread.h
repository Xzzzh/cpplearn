#ifndef _WD_THREAD_H__
#define _WD_THREAD_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{

class Thread
: Noncopyable
{
public:
	Thread();
	~Thread();

	pthread_t getThreadId() const
	{
		return _pthId;
	}

	bool isRunning() const
	{
		return _isRunning;
	}

	virtual void run()=0;
	void start();
	void join();
private:
//线程入口函数为什么设置为静态？
//因为非静态成员函数第一个参数为this，与pthread_create()参数类型要求不符
	static void * threadFunc(void *);
private:
	pthread_t _pthId;
	bool _isRunning;
};

}//end of namespace wd

#endif
