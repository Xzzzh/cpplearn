 ///
 /// @file    Thread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-09 15:59:44
 ///
 
#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

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

	virtual void run()=0;
	void start();
	void join();
private:
	static void * threadFunc(void *);
private:
	pthread_t _pthId;
	bool      _isRunning;

};

	
}//end of namespace wd

#endif
