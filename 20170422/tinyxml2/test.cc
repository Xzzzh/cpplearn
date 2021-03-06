///
/// @file    test.cc
/// @author  Xzzzh(sjzxzh@yeah.net)
/// @date    2017-04-24 15:53:35
///
#include "tinyxml2.h"
#include <boost/regex.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace tinyxml2;

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
	RssReader(const char * filename);
	void parseRss();
	void dump();
private:
	XMLDocument _doc;
	vector<RssItem> _rss;
};

RssReader::RssReader(const char * filename)
{
	_doc.LoadFile(filename);
	_rss.reserve(10);
}

void RssReader::parseRss()
{
	XMLElement * child_elec = _doc.FirstChildElement("rss")->FirstChildElement("channel")->FirstChildElement("item");
	string desc;
	string description;
	string content_row;
	string content_pure;
	string content_patten;
	content_patten = "<(.*)>";
	string n = " ";
	while (child_elec)
	{
		cout << endl;
		cout << child_elec->FirstChildElement("title")->GetText() << endl;
		cout << child_elec->FirstChildElement("link")->GetText() << endl;
		desc = child_elec->FirstChildElement("description")->GetText();
		description = desc;
		for (int i = 0; i < (int)desc.size(); i++)
		{
			if (desc[i] == '<')
			{
				description = desc.substr(0, i);
				break;
			}
		}
		cout << description << endl;
		content_row = child_elec->FirstChildElement("content:encoded")->GetText();
//		cout << content_row << endl;
		cout << " boost reg" << endl;
		boost::regex reg(content_patten);
		cout << "content pure" << endl;
		content_pure = boost::regex_replace(content_row, reg, string(" "));
//		cout << content_pure << endl;
		cout << "child elec" << endl;
		child_elec = child_elec->NextSiblingElement("item");
	}
}

void RssReader::dump()
{
	cout << "dump()" << endl;
}

int main(void)
{
	RssReader reader1("coolshell.xml");
	reader1.parseRss();
#if 0
	XMLDocument doc;
	doc.LoadFile("coolshell.xml");

	const char * title = doc.FirstChildElement("rss")->FirstChildElement("channel")->\
	                     FirstChildElement("item")->FirstChildElement("title")->GetText();
	string s(title);
	cout << s << endl;
	XMLText * textNode = doc.FirstChildElement("PLAY")->FirstChildElement("TITLE")->FirstChild()->ToText();
	title = textNode->Value();
	printf("Name of play(2): %s\n", title);
#endif
	return 0;
}
