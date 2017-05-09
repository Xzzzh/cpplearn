 ///
 /// @file    Subject.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-09 14:52:37
 ///

#ifndef __SUBJECT_H__
#define __SUBJECT_H__
 
#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::list;

typedef int State;

class Observer;

class Subject
{
public:
	void attach(Observer *);
	void detach(Observer *);
	void notify();

	virtual ~Subject(){}

	virtual State getState()=0;
	virtual void setState(State state)=0;

protected:
	State _subjectState;
	list<Observer*> _list;
};

class ConcreateSubject
: public Subject
{
public:
	State getState()
	{
		return _subjectState;
	}

	void setState(State state)
	{
		_subjectState = state;
		notify();
	}
};


class Observer
{
public:
	virtual ~Observer(){}
	virtual void update(Subject *)=0;
};

class ConcreateObserver
: public Observer
{
public:
	void update(Subject * p);
private:
	State _observerState;
};



#endif
