 ///
 /// @file    MutexLock.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-15 16:34:17
 ///
 
#include <unistd.h>
#include <pthread.h>

#include <iostream>
using std::cout;
using std::endl;


class MutexLock
{
public:
	MutexLock()
	: _isLocking(false)
	{
		pthread_mutex_init(&_mutex, NULL);
	}

	~MutexLock()
	{
		pthread_mutex_destroy(&_mutex);
	}

	void lock()
	{
		pthread_mutex_lock(&_mutex);
		_isLocking = true;
	}

	void unlock()
	{
		pthread_mutex_unlock(&_mutex);
		_isLocking = false;
	}

	bool isLocking() const
	{
		return _isLocking;
	}
private:
	MutexLock(const MutexLock &);
	MutexLock & operator=(const MutexLock &);
	
private:
	pthread_mutex_t _mutex;
	bool _isLocking;
};

class MutexLockGuard
{
//利用栈对象来保护资源:
//栈对象的特点：创建时自动调用构造函数，销毁时自动调用析构函数
public:
	MutexLockGuard(MutexLock & mutex)
	: _mutex(mutex)
	{
		_mutex.lock();
	}

	~MutexLockGuard()
	{
		_mutex.unlock();
	}

private:
	MutexLock & _mutex;
};

int num = 0;

void * func(void * arg)
{
	MutexLock * p = static_cast<MutexLock *>(arg);
	while(true)
	{
		MutexLockGuard guard(*p);
//		p->lock();
		++num;
		cout << "thread " << pthread_self() << ": num = " << num << endl;
		sleep(1);
//		p->unlock();
		return NULL;
	}
	return NULL;
}


int main(void)
{
	MutexLock mutex;

	pthread_t pth1;
	pthread_t pth2;
	pthread_create(&pth1, NULL, func, &mutex);
	pthread_create(&pth2, NULL, func, &mutex);
	sleep(3);
	
	cout <<"pth1 = " << pth1 << " , pth2 = " << pth2 << endl;

	pthread_join(pth1, NULL);
	pthread_join(pth2, NULL);

	cout <<"thread joined " << endl;
	return 0;
}
