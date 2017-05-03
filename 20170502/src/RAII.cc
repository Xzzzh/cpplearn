 ///
 /// @file    RAII.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-02 11:36:52
 ///
 
#include <iostream>
using std::cout;
using std::endl;


//自定义的智能指针
template <typename T>
class RAII
{
public:
	explicit RAII(T * p)
	: _p(p)
	{}

	T & operator*()const
	{
		return *_p;
	}

	T * operator->()
	{
		return _p;
	}

	T * get() const
	{
		return _p;
	}
	
	~RAII()
	{
		if(_p)
			delete _p;
	}

//private:
	RAII(const RAII&) = delete;
	RAII & operator=(const RAII&) = delete;

private:
	T * _p;
};

class SomeResource
{
public:
	SomeResource()
	{
		cout << "SomeResource()" << endl;
	}

	~SomeResource()
	{
		cout << "~SomeResource()" << endl;
	}

	void display()
	{
		cout << "SomeResource::display()" << endl;
	}
};

class Example
{
public:
	Example()
	: _p1(new SomeResource())
	, _p2(new SomeResource())
	{}

	Example(const Example & rhs)
	: _p1(new SomeResource(*(rhs._p1)))
	, _p2(new SomeResource(*rhs._p2))
	{
	
	}

	Example & operator=(const Example & rhs)
	{
		if(this != &rhs)
		{
			*_p1 = *rhs._p1;
			*_p2 = *rhs._p2;
		}
		return *this;
	}

	void print()
	{
		_p1->display();
		_p2->display();
	}

private:
	RAII<SomeResource> _p1;
	RAII<SomeResource> _p2;
};


int main(void)
{
	Example ex;
	ex.print();

	return 0;
}

