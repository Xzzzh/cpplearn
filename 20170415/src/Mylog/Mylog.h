 ///
 /// @file    Mylog.h
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-15 17:11:56
 ///
 
#ifndef __WD_MYLOG_H__
#define __WD_MYLOG_H__

#include <log4cpp/Category.hh>
#include <string>
#include <sstream>

using std::string;
using std::ostringstream;

class Mylog
{
public:
	static Mylog * getInstance();
	static void destroy();
	
	void warn(const char * msg);
	void error(const char * msg);
	void info(const char * msg);
	void debug(const char * msg);
private:
	Mylog();
	~Mylog();

private:
	log4cpp::Category & _cat;
	static Mylog * _pInstance;
};

inline string int2str(int num)
{
	ostringstream oss;
	oss << num;
	return oss.str();
}

#define prefix(msg) string("[").append(__FILE__).append(":")\
	.append(__func__).append(":")\.append(int2str(__LINE__)).append("]")\
	.append(msg).c_str()

void logWarn(const char * msg);
void logError(const char * msg);
void logDebug(const char * msg);
void logInfo(const char * msg);

#endif
