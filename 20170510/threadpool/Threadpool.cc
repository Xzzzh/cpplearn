#include "Threadpool.h"
#include "ThreadpoolThread.h"
#include "Task.h"
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

Threadpool::Threadpool(size_t buffsize, size_t threadNum)
: _buffsize(buffsize)
, _threadNum(threadNum)
, _buffer(_buffersize)
, _isExit(false)
{}

void Threadpool::start()
{
	for(size_t idx = 0; idx != _threadNum; ++idx)
	{
		shared_ptr<Thread> sp(new ThreadpoolThread(*this));
		_threads.push_back(sp);
		sp->start();
	}
}

void Threadpool::stop()
{
	cout << "Threadpool::stop()" << endl;
	if(!_isExit)
	{
		while(!_buffer.empty())
		{
			sleep(1);//等待缓冲区中的任务执行结束
		}
		_isExit = true;
		_buffer.wakeup();

		for(auto & elem : _threads)
		{
			elem->join();
		}
	}
}

void Threadpool::addTask(Task * task)
{
	return _buffer.push(task);
}

Tesk * Threadpool::getTask()
{
	return _buffer.pop();
}

void Threadpool::threadFunc()
{
	while(!_isExit)
	{
		Task * task = getTask();
		if(task)
			task->execute();
	}
}

}//end of namespace wd
