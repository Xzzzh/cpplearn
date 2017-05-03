#include <assert.h>
#include <ctype.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string> //string--> vector<char>
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
	static const int kInit = 100;//控制vector初始化的空间数
	vector<string> _lines;//存储一行的数据?
	map<string, int> _dict;//存储单词和出现的频率

	//     注意这里两个 >> 不能挨在一起
	map<string, set<int> > _word2Line;//存储一个单词所在的所有行
};

TextQuery::TextQuery()
{
	//预先申请好一定大小的空间
	_lines.reserve(kInit);
}

// 封装成函数类以满足not1接口要求
struct NotAlpha //: public std::unary_function<char, bool>
{
	bool operator()(char ch) const
	{
		return (!isalpha(ch));
	}
};

//继承？不太懂
struct IsAlpha : public std::unary_function<char, bool>
{
	bool operator()(char ch) const
	{
		return (isalpha(ch));
	}
};

#if 0
void test()
{
	char * p = NULL;
	assert(p != NULL);//running assert
	(void)p;

	static_assert((p != 0), "nullptr exception");//compiling assert
	//argument must be a constant expression

	static_assert(sizeof(p) == 8, "no support for 32bit system");
	//only working in compiling, not involved in source code
}
#endif

void TextQuery::readFile(const string & filename)
{
	ifstream ifs(filename);
	//ifs 作为流对象，会有状态，assert会去判断ifs的状态
	assert(ifs);
	//多用assert方法来判断指针或者对象初始化是否异常

	string line;
	int cnt = 0;//cnt表示行号
	while(getline(ifs, line))
	{
		_lines.push_back(line);
//		replace_if(line.begin(), line.end(), std::not1(isalpha), ' ');//Error
		replace_if(line.begin(), line.end(), NotAlpha(), ' ');
	//	replace_if(line.begin(), line.end(), std::not1(IsAlpha()), ' ');
		cout << cnt << ":" << line << endl;

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
	cout << word << " occurs " << freq << (freq > 0 ? " times. " : " time. ") << endl;
	set<int> & lines = _word2Line[word];
	for (auto & elem : lines)
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
