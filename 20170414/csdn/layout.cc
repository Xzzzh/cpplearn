 ///
 /// @file    layout.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-14 20:54:02
 ///
 
#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>

using std::cout;
using std::endl;

int main(void)
{
	log4cpp::OstreamAppender * osApd = new log4cpp::OstreamAppender("osApender", &cout);

	log4cpp::PatternLayout * playout = new log4cpp::PatternLayout();
	playout->setConversionPattern("%d: %p %c %x: %m%n");
	osApd->setLayout(playout);

	log4cpp::Category & root = log4cpp::Category::getRoot();
	log4cpp::Category & info = root.getInstance("infoCategory");
	info.addAppender(osApd);
	info.setPriority(log4cpp::Priority::INFO);

	info.info("system now running");
	info.warn("system has a warning");
	info.error("system error");
	info.fatal("system fatal");
	info.info("system shutdown");

	log4cpp::Category::shutdown();
	return 0;
}
