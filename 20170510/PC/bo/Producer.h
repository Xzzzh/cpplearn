#ifndef __WD_PRODUCER_H__
#define __WD_PRODUCER_H__

#include "Buffer.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using std::cout;
using std::endl;

class Producer
{
public:
	void execute(wd::Buffer & buffer)
	{
		::srand(::time(NULL));
		while(true)
		{
			int number = ::rand() % 100;
			buffer.push(number);
			cout << "Producer a number: " << number << endl;
			sleep(1);
		}
	}
};

#endif
