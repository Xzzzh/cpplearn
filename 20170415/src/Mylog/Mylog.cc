 ///
 /// @file    Mylog.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-15 17:25:56
 ///
 
#include "Mylog.h"

#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>


#include <iostream>
using std::cout;
using std::endl;

Mylog * Mylog::_pInstance = NULL;

Mylog * Mylog::getInstance()
{
	if(NULL == _pInstance)
		_pInstance = new Mylog;
	return _pInstance;
}

void Mylog::destroy()
{
	if(_pInstance)
		delete _pInstance;
}

Mylog::Mylog()
: _cat(log4cpp::Category::getRoot().getInstance("Mycat"))
{
	log4cpp::PatternLayout * ptn1 = new log4cpp::PatternLayout();
	ptn1->setConversionPattern("%d [%p] %c : %m %n");
	
	log4cpp::PatternLayout * ptn2 = new log4cpp::PatternLayout();
	ptn2->setConversionPattern("%d [%p] %c : %m %n");

	log4cpp::OstreamAppender * os = new log4cpp::OstreamAppender("os", &cout);
	os->setLayout(ptn1);

	log4cpp::FileAppender * file = new log4cpp::FileAppender("file", "wd.log");
	file->setLayout(ptn1);

	_cat.addAppender(os);
	_cat.addAppender(file);
	_cat.setPriority(log4cpp::Priority::DEBUG);

}

Mylog::~Mylog()
{
	log4cpp::Category::shutdown();
}

void Mylog::warn(const char * msg)
{
	_cat.warn(msg);
}

void Mylog::error(const char * msg)
{
	_cat.error(msg);
}

void Mylog::info(const char * msg)
{
	_cat.info(msg);
}

void Mylog::debug(const char * msg)
{
	_cat.debug(msg);
}

void logError(const char * msg)
{
	Mylog::getInstance()->error(msg);
}

void logWarn(const char * msg)
{
	Mylog::getInstance()->warn(msg);
}

void logInfo(const char * msg)
{
	Mylog::getInstance()->info(msg);
}

void logDebug(const char * msg)
{
	Mylog::getInstance()->debug(msg);
}
