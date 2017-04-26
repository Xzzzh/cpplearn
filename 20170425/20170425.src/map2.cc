 ///
 /// @file    map2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-25 16:35:47
 ///
 
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::multimap;
using std::pair;
using std::string;



int test0(void)
{
	pair<int, string> t(600036, "招商银行");
	cout << t.first << "--->" << t.second << endl;

	// map中不能存放关键字相同的元素,默认情况下按从小到大的顺序进行排列
	multimap<int, string> mapIntStr{
		pair<int, string>(3, "北京"),
		pair<int, string>(2, "广州"),
		pair<int, string>(1, "深圳"),
		pair<int, string>(2, "上海")};

	multimap<int,string>::iterator it;
	for(it = mapIntStr.begin();
		it != mapIntStr.end();
		++it)
	{
		cout << it->first << "-->" << it->second << endl;
	}

	return 0;
}

int test1(void)
{
	pair<string, string> t("600036", "招商银行");
	cout << t.first << "--->" << t.second << endl;

	// map中不能存放关键字相同的元素,默认情况下按从小到大的顺序进行排列
	multimap<string, string, std::greater<string> > mapIntStr{
		std::make_pair("A", "北京"),
		std::make_pair("B", "广州"),
		std::make_pair("C", "深圳"),
		std::make_pair("B", "上海")};

	multimap<string,string>::iterator it;
	for(it = mapIntStr.begin();
		it != mapIntStr.end();
		++it)
	{
		cout << it->first << "-->" << it->second << endl;
	}

	return 0;
}

int main(void)
{
	test0();
	test1();
	return 0;
}
