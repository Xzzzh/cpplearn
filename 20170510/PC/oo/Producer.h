#ifndef __WD_PRODUCER_H__
#define __WD_PRODUCER_H__

#include "Thread.h"

namespace wd
{
class Buffer;

class Producer
: public Thread
{
public:
	Producer(Buffer & buff);
	virtual void run();
private:
	Buffer & _buff;
};

}//end of namespace wd

#endif
