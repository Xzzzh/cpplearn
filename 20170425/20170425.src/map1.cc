 ///
 /// @file    map1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-25 16:35:47
 ///
 
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;



int test0(void)
{
	pair<int, string> t(600036, "招商银行");
	cout << t.first << "--->" << t.second << endl;

	// map中不能存放关键字相同的元素,默认情况下按从小到大的顺序进行排列
	map<int, string> mapIntStr{
		pair<int, string>(3, "北京"),
		pair<int, string>(2, "广州"),
		pair<int, string>(1, "深圳"),
		pair<int, string>(2, "上海")};

	map<int,string>::iterator it;
	for(it = mapIntStr.begin();
		it != mapIntStr.end();
		++it)
	{
		cout << it->first << "-->" << it->second << endl;
	}

	//map支持下标访问运算符, map并不支持随机访问(时间复杂度是O(1))迭代器
	//map只支持双向迭代器
	mapIntStr[4] = "东莞";
	mapIntStr[3] = "天津";
	cout << "对map做修改之后:" << endl;
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
	pair<string, string> t("600036", "招商银行");
	cout << t.first << "--->" << t.second << endl;

	// map中不能存放关键字相同的元素,默认情况下按从小到大的顺序进行排列
	map<string, string, std::greater<string> > mapIntStr{
		pair<string, string>("A", "北京"),
		pair<string, string>("B", "广州"),
		pair<string, string>("C", "深圳"),
		pair<string, string>("B", "上海")};

	map<string,string>::iterator it;
	for(it = mapIntStr.begin();
		it != mapIntStr.end();
		++it)
	{
		cout << it->first << "-->" << it->second << endl;
	}

	//map支持下标访问运算符,其关键字类型可以是任意类型
	//map并不支持随机访问(时间复杂度是O(1))迭代器
	//map只支持双向迭代器
	mapIntStr["E"] = "东莞";
	mapIntStr["B"] = "天津";
	cout << "对map做修改之后:" << endl;
	for(it = mapIntStr.begin();
		it != mapIntStr.end();
		++it)
	{
		cout << it->first << "-->" << it->second << endl;
	}

	return 0;
}
