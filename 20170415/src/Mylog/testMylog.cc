 ///
 /// @file    testMylog.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-15 17:42:59
 ///
 
#include "Mylog.h"

#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	logError("error");
	logWarn("error");
	logInfo("error");
	logDebug("error");
	
	return 0;
}
