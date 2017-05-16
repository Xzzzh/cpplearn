#include "Consumer.h"
#include "Buffer.h"
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
Consumer::Consumer(Buffer & buff)
: _buff(buff)
{

}
void Consumer::run()
{
	while(true)
	{
		int number = _buff.pop();
		
		cout << "Thread " << pthread_self() << " Consume a number:" << number << endl;
		sleep(1);
	}
}

}//end of namespace wd
