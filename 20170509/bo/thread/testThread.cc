 ///
 /// @file    testThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-09 16:14:59
 ///


#include "Thread.h" 

#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Test
{
public:
	void doTask()
	{
		::srand(::time(NULL));
		while(true)
		{
			int number = ::rand() % 100;
			cout << "nubmer = " << number << endl;
			::sleep(1);
		}
	}
};


int main(void)
{
	wd::Thread thread(std::bind(&Test::doTask, Test()));

	thread.start();
	thread.join();

	return 0;
}
