#ifndef __WD_CONSUMER_H__
#define __WD_CONSUMER_H__

#include "Thread.h"

namespace wd
{

class Buffer;

class Consumer
: public Thread
{
public:
	Consumer(Buffer & buff);

	virtual void run();
private:
	Buffer & _buff;
};

}//end of namespace wd

#endif
