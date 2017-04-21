 ///
 /// @file    log4cpp2.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-14 17:08:25
 ///
#include <log4cpp/Category.hh> 
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>

#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	log4cpp::PatternLayout *ptn1 = new log4cpp::PatternLayout();
	ptn1->setConversionPattern("%d %c [%p] : %m%n");

	log4cpp::OstreamAppender * pOsAp = new log4cpp::OstreamAppender("OstreamAppender", & cout);
	pOsAp->setLayout(ptn1);

	log4cpp::Category & root = log4cpp::Category::getRoot();
	log4cpp::Category & infoCat = root.getInstance("InfoCat");
	infoCat.setAppender(pOsAp);
	infoCat.setPriority(log4cpp::Priority::INFO);
	
	infoCat.error("error message!");
	infoCat.warn("warn message!");
	infoCat.debug("debug message!");
	infoCat.fatal("fatal message!");
	infoCat.info("info message!");

	log4cpp::Category::shutdown();

	return 0;
}
