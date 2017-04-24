 ///
 /// @file    myxmltest.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-24 15:23:52
 ///
 
#include "tinyxml2.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>

using namespace tinyxml2;
using namespace std;

struct RssItem
{
	string title;
	string link;
	string description;
	string content;
};

class RssReader
{
public:
	RssReader(string & filename);

	void parseRss();//解析
	void dump();//输出
private:
	vector<RssItem> _rss;
	XMLDocument	_doc;
};

RssReader::RssReader(string & filename)
{
	_doc.LoadFile(filename.c_str());
}


int main(void)
{


	return 0;
}
