#ifndef __WD_CONSUMER_H__
#define __WD_CONSUMER_H__
#include "Buffer.h"
#include <iostream>

using std::cout;
using std::endl;

class Consumer
{
public:
	void execute(wd::Buffer & Buffer)
	{
		while(true)
		{
			int number = buffer.pop();
			cout << "consume a number:" << number << endl;
			sleep(2);
		}
	}
};

#endif
