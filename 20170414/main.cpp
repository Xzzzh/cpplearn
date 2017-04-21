 ///
 /// @file    main.cpp
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-14 10:35:13
 ///
 
#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char ** argv)
{
	log4cpp::Appender *appender1 = new log4cpp::OstreamAppender("console", &std::cout);
	appender1->setLayout(new log4cpp::BasicLayout());

	log4cpp::Appender *appender2 = new log4cpp::FileAppender("default", "program.log");
	appender2->setLayout(new log4cpp::BasicLayout());

	log4cpp::Category & root = log4cpp::Category::getRoot();
	root.setPriority(log4cpp::Priority::WARN);
	root.addAppender(appender1);

	log4cpp::Category & sub1 = log4cpp::Category::getInstance(std::sring("sub1"));
	sub1.
	return 0;
}
