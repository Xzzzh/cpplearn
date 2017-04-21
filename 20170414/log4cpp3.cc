 ///
 /// @file    log4cpp3.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-14 17:08:25
 ///
#include <log4cpp/Category.hh> 
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/RollingFileAppender.hh>

#include <iostream>
using std::cout;
using std::endl;
using std::ostringstream;

int main(void)
{
	log4cpp::PatternLayout *ptn1 = new log4cpp::PatternLayout();
	ptn1->setConversionPattern("%d %c [%p] : %m%n");

	log4cpp::PatternLayout *ptn2 = new log4cpp::PatternLayout();
	ptn2->setConversionPattern("%d %c [%p] : %m%n");

	log4cpp::FileAppender * pfileApd = 
		new log4cpp::FileAppender("fileApd", "wd.log");
	pfileApd->setLayout(ptn1);

	log4cpp::OstreamAppender * pOsAp = 
		new log4cpp::OstreamAppender("OstreamAppender", & cout);
	pOsAp->setLayout(ptn1);

	log4cpp::RollingFileAppender * prfileApd = 
		new log4cpp::RollingFileAppender(
				"RollingFileAppender",
				"rollingwd.log",
				5 * 1024,
				1);
	prfileApd->setLayout(ptn2);

	log4cpp::Category & root = log4cpp::Category::getRoot();
	log4cpp::Category & infoCat = root.getInstance("InfoCat");
	log4cpp::Category & debugCat = root.getInstance("Debugcat");
	debugCat.addAppender(pfileApd);
	debugCat.addAppender(prfileApd);
	debugCat.setPriority(log4cpp::Priority::DEBUG);

	for(size_t idx = 0; idx != 100; ++idx)
	{
		ostringstream oss;
		oss << idx << ":Root Error Message!";
		debugCat.error(oss.str());
	
	}
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
