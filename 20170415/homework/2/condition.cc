 ///
 /// @file    condition.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-19 09:46:46
 ///
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

class Condition;
class MutexLockGuard;

class MutexLock
{
friend Condition;
friend MutexLockGuard;
public:
	MutexLock();
	~MutexLock();
	bool islocking() const;

	void lock();
	void unlock();
private:
	pthread_mutex_t & getMutex();
	MutexLock(const MutexLock &);
	MutexLock & operator=(const MutexLock &);
private:
	pthread_mutex_t _mutex;
	bool _islocking;
};

MutexLock::MutexLock()
: _islocking(false)
{
	pthread_mutex_init(&_mutex, NULL);
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_mutex);
}

void MutexLock::lock()
{
	pthread_mutex_lock(&_mutex);
	_islocking = true;
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
	_islocking = false;
}

bool MutexLock::islocking() const
{
	return _islocking;
}

pthread_mutex_t & MutexLock::getMutex()
{
	return _mutex;
}

class MutexLockGuard
{
public:
	MutexLockGuard(MutexLock &);
	~MutexLockGuard();

	void guardlock();
	void guardunlock();
private:
	MutexLock & _mutex;
};

MutexLockGuard::MutexLockGuard(MutexLock & lock)
: _mutex(lock)
{
	_mutex.lock();
}

MutexLockGuard::~MutexLockGuard()
{
	_mutex.unlock();
}


class Condition
{
public:
	Condition(MutexLock &);
	~Condition();
	
	void wait();
	void notify();
	void notifyall();
private:	
	pthread_cond_t _cond;
	MutexLock & _mutex;
};

Condition::Condition(MutexLock & mutex)
: _mutex(mutex)
{
	pthread_cond_init(&_cond, NULL);
}

Condition::~Condition()
{
	pthread_cond_destroy(&_cond);
}

void Condition::wait()
{
	pthread_cond_wait(&_cond, &_mutex.getMutex());
}

void Condition::notify()
{
	pthread_cond_signal(&_cond);	
}

void Condition::notifyall()
{
	pthread_cond_broadcast(&_cond);	//broadcast 是唤醒所有在wait状态的cond，而signal只唤醒一个
}
