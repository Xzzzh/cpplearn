 ///
 /// @file    1.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-14 21:51:28
 ///
 

#include <log4cpp/Category.hh>
#include <log4cpp/NDC.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/OstreamAppender.hh>

#include <iostream>

#define LOGFILENAME "Mylog.log"

using std::cout;
using std::endl;
using std::ostringstream;

class Mylog
{
public:
	static Mylog * getInstance()
	{
		if (_pInstance == NULL)	
		{
			_pInstance = new Mylog;	
		}
		return _pInstance;
	}
	
	static void destroy()
	{
		if (_pInstance)
			cout << "destroy(): Mylog woll be destroy" << endl;
			delete _pInstance;
	}

private:

	Mylog()
	: _pLayout1(new log4cpp::PatternLayout())
	, _pLayout2(new log4cpp::PatternLayout())
	, _pOsApd(new log4cpp::OstreamAppender("OstreamAppender", &cout))
	, _pRfApd(new log4cpp::RollingFileAppender("RollingFileAppender", LOGFILENAME, 5 * 1024, 1))
	, _root(log4cpp::Category::getRoot().getInstance("RootName"))
	, _warnCat(_root.getInstance("WarnCat"))
/*	, _errorCat(_root.getInstance("ErrorCat"))
	, _debugCat(_root.getInstance("DebugCat"))
	, _infoCat(_root.getInstance("InfoCat"))
*/
	{
		_pLayout1->setConversionPattern("%d %c [%p] : %m%n");	
		_pLayout2->setConversionPattern("%d %c [%p] : %m%n");	
		_pOsApd->setLayout(_pLayout1);
		_pRfApd->setLayout(_pLayout2);

		_warnCat.setAppender(_pOsApd);
		_warnCat.setAppender(_pRfApd);
		_warnCat.setPriority(log4cpp::Priority::WARN);

/*		_errorCat.setAppender(_pOsApd);
		_errorCat.setAppender(_pRfApd);
		_errorCat.setPriority(log4cpp::Priority::ERROR);

		_debugCat.setAppender(_pOsApd);
		_debugCat.setAppender(_pRfApd);
		_debugCat.setPriority(log4cpp::Priority::DEBUG);

		_infoCat.setAppender(_pOsApd);
		_infoCat.setAppender(_pRfApd);
		_infoCat.setPriority(log4cpp::Priority::INFO);
*/		
	}

	~Mylog()
	{
		cout << "~Mylog: Mylog  woll be destroy" << endl;
		log4cpp::NDC::clear();
		log4cpp::Category::shutdown();	
	}

public:

	void warn(const char * msg)
	{
		_warnCat.warn(msg);	
	}
/*
	void error(const char * msg)
	{
		_errorCat.error(msg);	
	}

	void debug(const char * msg)
	{
		_debugCat.debug(msg);	
	}

	void info(const char * msg)
	{
		_infoCat.info(msg);	
	}
*/
private:
	
	static Mylog * _pInstance;	

	log4cpp::PatternLayout * _pLayout1;
	log4cpp::PatternLayout * _pLayout2;
	log4cpp::OstreamAppender * _pOsApd;
	log4cpp::RollingFileAppender * _pRfApd;
	log4cpp::Category & _root;
	log4cpp::Category & _warnCat;
/*
	log4cpp::Category & _errorCat;
	log4cpp::Category & _debugCat;
	log4cpp::Category & _infoCat;
*/
};

Mylog * Mylog::_pInstance = NULL;

int main(void)
{
	cout << "Program running..." << endl;

	Mylog * plog = Mylog::getInstance();

	plog->warn("Warn");
/*	plog->error("Error");
	plog->debug("Debug");
	plog->info("Info");
*/
	cout << "Mylog will be destroied" << endl;
	Mylog::destroy();
	cout << "Mylog destroied" << endl;
	return 0;
}
