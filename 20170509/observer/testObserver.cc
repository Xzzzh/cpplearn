 ///
 /// @file    testObserver.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-09 15:12:01
 ///
 
#include "Subject.h"
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	Subject * pSubject = new ConcreateSubject();

	Observer * p1 = new ConcreateObserver();
	Observer * p2 = new ConcreateObserver();
	Observer * p3 = new ConcreateObserver();

	pSubject->attach(p1);
	pSubject->attach(p2);
	pSubject->attach(p3);
	pSubject->setState(1);
	pSubject->setState(2);
	pSubject->detach(p1);
	pSubject->setState(3);
	

	return 0;
}


