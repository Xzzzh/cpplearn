
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;

int main(void)
{
	pair<int, string> t(600036, "招商银行");
	cout << t.first << "---->" << t.second << endl;
	//map中不嫩个存放关键字相同的元素， 默认情况下按照从小到大的顺序进行存储
	map<int, string> mapIntStr
	{
		pair<int, string>(3, "beijing");
		pair<int, string>(2, "guangzhou");
		pair<int, string>(5, "shenzhen");
		pair<int, string>(2, "shanghai");

	}
	map<int, string>::iterator it;
	for (it = mapIntStr.begin();
	        it != mapIntStr.end();
	        ++it)
	{
		cout << it->first << "---->" << it->second << endl;
	}

	//map支持下标访问运算符，实质是查找而不是随机访问，时间复杂度是
	//long(n)
	//map只支持双向迭代器
	mapIntStr[4] = "dongguan";
	mapIntStr[1] = "dongguan";
	cout << "after change map" << endl;
	for (it = mapIntStr.begin()
	     it != mapIntStr.end();
	     ++it)
	{
		cout << it->first << "---->" << it->second << endl;
	}
		return 0;
}
