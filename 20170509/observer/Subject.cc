 ///
 /// @file    Subject.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-09 15:00:36
 ///
 
#include "Subject.h"
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;




void Subject::attach(Observer * observer)
{
	_list.push_back(observer);
}

void Subject::detach(Observer * observer)
{
	auto it = std::find(_list.begin(), _list.end(), observer);
	if(it != _list.end())
	{
		_list.erase(it);
	}
}


void Subject::notify()
{
	cout << "通知所有的观察者" << endl;
	for(auto & item : _list)
	{
		item->update(this);
	}
}



//update方法的参数可以有两种：
//1.　传一个主题的引用或者指针,叫拉模式
//2.  直接传一个消息过来,叫推模式
//					
//void ConcreateObserver::update(State state)
void ConcreateObserver::update(Subject * subject)
{
	if(subject)
	{
		_observerState = subject->getState();
		cout << "观察者更新状态:" << _observerState <<  endl;
	}
}
