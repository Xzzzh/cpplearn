 ///
 /// @file    testLine.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-19 20:12:19
 ///
 
#include "Line.h"
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	Line line(1, 3, 4, 5);
	line.printLine();
	cout << endl;
	return 0;
}
