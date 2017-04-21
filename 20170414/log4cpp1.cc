 ///
 /// @file    log4cpp1.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-14 17:08:25
 ///
#include <log4cpp/Category.hh> 
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>

#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	log4cpp::OstreamAppender * pOsAp = new log4cpp::OstreamAppender("OstreamAppender", & cout);
	pOsAp->setLayout(new log4cpp::BasicLayout());

	log4cpp::Category & root = log4cpp::Category::getRoot();
	root.setAppender(pOsAp);
	root.setPriority(log4cpp::Priority::DEBUG);

	root.error("error message!");
	root.warn("warn message!");
	root.debug("debug message!");

	log4cpp::Category::shutdown();

	return 0;
}
