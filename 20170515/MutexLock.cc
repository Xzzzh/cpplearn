#include "MutexLock.h"
#include <iostream>

using std::cout;
using std::endl;

namespace wd
{

MutexLock::MutexLock()
{
	pthread_mutex_init(&m_mutex, NULL);
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&m_mutex);
}

void MutexLock::lock()
{
	pthread_mutex_lock(&m_mutex);
}

void MutexLock::unlock()
{

	pthread_mutex_unlock(&m_mutex);
}
pthread_mutex_t * MutexLock::getMutexLockPtr()
{
	return & m_mutex;
}

}//end of namespace wd
