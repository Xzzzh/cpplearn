#ifndef __NONCOPYABLE_H__
#define __NONCOPYABLE_H__

namespace wd
{

class Noncopyable
{
protected:
	Noncopyable() {}
	~Noncopyable() {}
private:
	Noncopyable(const Noncopyable &);
	Noncopyable & operator=(const Noncopyable &);
};

}//end of namespace wd

#endif
