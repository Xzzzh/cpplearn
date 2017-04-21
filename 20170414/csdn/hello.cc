 ///
 /// @file    hello.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-14 20:37:23
 ///
 
#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>

using std::cout;
using std::endl;

int main(void)
{
	//创建一个osApd并指定其包含的laylout
	log4cpp::OstreamAppender * osApd = new log4cpp::OstreamAppender("osAppender", &cout);
	osApd->setLayout(new log4cpp::BasicLayout());

	//从系统中得到Category的根，将osApd添加到该category中
	log4cpp::Category & root = log4cpp::Category::getRoot();
	root.addAppender(osApd);

	//设置category的优先级
	root.setPriority(log4cpp::Priority::DEBUG);
	
	//记录日志
	root.error("Hello log4cpp in a Error Message!");
	root.warn("Hello log4cpp in a Warning Message!");

	//关闭category
	log4cpp::Category::shutdown();

	return 0;
}
