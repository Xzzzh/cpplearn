 ///
 /// @file    TextQuery.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-01 10:55:06
 ///

#include <assert.h>
#include <ctype.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>  //string-->  vector<char>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>


using std::cout;
using std::endl;
using std::string;
using std::set;
using std::map;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::replace_if;

static_assert(sizeof(void*) == 8, "not supported");

class TextQuery
{
public:
	TextQuery();
	void readFile(const string & filename);
	void query(const string & word);
private:
	static const int kInit = 100;
	vector<string> _lines;
	map<string, int> _dict;
	map<string, set<int> > _word2Line;
};

TextQuery::TextQuery()
{
	_lines.reserve(kInit);
}


struct NotAlpha //: public std::unary_function<char, bool>
{
	bool operator()(char ch) const
	{
		return (!isalpha(ch));
	}
};

struct IsAlpha : public std::unary_function<char, bool>
{
	bool operator()(char ch) const
	{
		return (isalpha(ch));
	}
};


void test()
{
	//char * p = NULL;
	//assert(p != NULL);//使用assert断言,运行时断言
	//(void)p;
	//static_assert((p != 0), "nullptr exception");// 编译时断言, 必须要求是一个常量表达式
	//static_assert(sizeof(p) == 8, "不支持32位系统");//只在编译时起作用，代码不会进入到源码
}


void TextQuery::readFile(const string & filename)
{ 
	ifstream ifs(filename);
	assert(ifs);//assert方法可以多使用，用来判断指针或者对象初始化是否异常

	string line;
	int cnt = 0;
	while(getline(ifs, line))
	{ 
		_lines.push_back(line);
		
		//replace_if(line.begin(), line.end(), std::not1(isalpha), ' ');//Error
		replace_if(line.begin(), line.end(), NotAlpha(), ' ');
		//replace_if(line.begin(), line.end(), std::not1(IsAlpha()), ' ');

		cout <<  cnt << ":" << line << endl;

		istringstream iss(line);
		
		string word;

		while(iss >> word)
		{
			++_dict[word];
			
			_word2Line[word].insert(cnt);
		}
		++cnt;
	}
	ifs.close();
}

void TextQuery::query(const string & word)
{
	int freq = _dict[word];
	cout << word << " occurs " << freq << (freq > 0 ? " times.":" time.") << endl;
	set<int> & lines = _word2Line[word];
	for(auto & elem : lines)
	{
		cout << "    (line " << elem + 1 << ")" << _lines[elem] << endl;
	}
}

int main(void)
{
	TextQuery tq;
	tq.readFile("china_daily.txt");
	tq.query("still");

	return 0;
}
