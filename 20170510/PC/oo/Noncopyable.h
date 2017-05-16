#ifndef _WD_NONCOPYABLE_H__
#define _WD_NONCOPYABLE_H__

//使用不可复制的类作为基类
//方法是将复制构造函数和赋值运算符函数
//设置为private
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
