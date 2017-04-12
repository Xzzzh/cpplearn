 ///
 /// @file    MutexLock.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-12 22:18:50
 ///
 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include <iostream>
using std::cout;
using std::endl;

class MutexLock
{
public:
	MutexLock();
	~MutexLock();

	void lock();
	void unlock();
private:
	pthread_mutex_t * _lock;//定义pthread_mutex_t 类型的变量用于加锁解锁
};

MutexLock::MutexLock()
: _lock(new pthread_mutex_t)
{
	cout << "lock init" << endl;
	pthread_mutex_init(_lock, NULL);
}

MutexLock::~MutexLock()
{
	cout << "lock destroy" << endl;
	pthread_mutex_destroy(_lock);
	delete _lock;
}

void MutexLock::lock()
{
	pthread_mutex_lock(_lock);
	cout << "mutex locked" << endl;
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(_lock);
	cout << "mutex unlocked" << endl;
}

int main(void)
{
	MutexLock lock;
	int num = 0;
	for (int i = 0; i < 10; i++)
	{
		lock.lock();
		num += 1;
		lock.unlock();
	}

	cout << "total sum num =:" << num << endl;
	return 0;
}
