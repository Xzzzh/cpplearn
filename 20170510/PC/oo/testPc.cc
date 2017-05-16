#include "Producer.h"
#include "Consumer.h"
#include "Buffer.h"

#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using std::endl;
using std::cout;

int main(void)
{
	wd::Buffer buffer(10);
	wd::Thread * pProducer = new wd::Producer(buffer);
	wd::Thread * pConsumer = new wd::Consumer(buffer);

	pProducer->start();
	pConsumer->start();

	pProducer->join();
	pConsumer->join();

	return 0;
}
