#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::multimap;
using std::string;
using std::pair;

template <typename Container>
void display(Container & c)
{
	//什么时候必须加上typename？
	//当模板中的类型名为类型参数时？否则编译器不知道它是一个类
	typename Container::iterator it;
	//Container::iterator it;
	for (it = c.begin(); it != c.end(); ++it)
	{
		cout << it->first << "--->" << it->second << endl;
	}
}

void test0(void)
{
	//也必须是在C++11标准后
	map<int, string> mapIntStr{
		std::make_pair(1, "AA"),
		std::make_pair(3, "BB")
	};

	pair<int, string> elem(3, "XX");

	map<int, string>::iterator it = mapIntStr.begin();
	//pair<map<int, string>::iterator, bool> ret = mapIntStr.insert(elem);//不如用auto方便
	auto ret = mapIntStr.insert(elem);

	if(ret.second)
	{
		cout << "添加成功:"
			 << ret.first->first << "--->"
			 << ret.first->second << endl;
	}
	else
	{
		cout << "添加失败，原容器中已有相同关键字的元素！" << endl;
	}

	display(mapIntStr);
}

void test1(void)
{
	multimap<int, string> mapIntStr{
		std::make_pair(1, "AA"),
		std::make_pair(1, "BB")
	};

	pair<int, string> elem(2, "XX");

	map<int, string>::iterator it = mapIntStr.insert(elem);

	cout << it->first << "--->" << it->second << endl;
	cout << "===============" << endl;

	display(mapIntStr);
}

int main(void)
{
	test0();
	cout << "============" << endl;
	test1();

	return 0;
}
