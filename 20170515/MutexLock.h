#ifndef __WD_MUTEXLOCK_H__
#define __WD_MUTEXLOCK_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{

class MutexLock : Noncopyable
{
public:
	MutexLock();
	~MutexLock();
	
	pthread_mutex_t * getMutexLockPtr();

	void lock();
	void unlock();
private:
	pthread_mutex_t m_mutex;
};

class MutexLockGuard
{
public:
	MutexLockGuard(MutexLock & mutex)
	: m_mutex(mutex)
	{
		m_mutex.lock();
	}
	~MutexLockGuard()
	{
		m_mutex.unlock();
	}
private:
	MutexLock & m_mutex;
};
	
}//end of namespace wd

#endif
