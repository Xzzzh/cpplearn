 ///
 /// @file    WordStatistic.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-15 15:24:24
 ///
 
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istringstream;

//Record 类用于存放某个单词和其出现频率,作为vector的元素
struct Record
{
	//构造函数定义成const防止被修改, & 不调用复制构造函数
	Record(const string & w, int f)
	: word(w)
	, freq(f)
	{}
	// 运算符重载函数, 不懂
	bool operator <(const Record & rhs) const
	{
		return this->word < rhs.word;	
	}
	//数据结构
	string word;
	int freq;
};

//将文件的读取和结果写出封装成单独的类
class WordStatistic
{
	//为什么不需要构造函数？
public:
	void readFile(const string & filename);
	void writeFile(const string & filename);
private:
	//vector<tpye> vectorname;
	vector<Record> _dict;
};

void WordStatistic::readFile(const string & filename)
{
	//输入文件流 ifs
	ifstream ifs;
	//打开文件 需要用string类的.c_str()方法转string类为char *
	ifs.open(filename.c_str());
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return ;
	}

	string line;//读取一行的数据
	string word;//读取的单词
	_dict.reserve(10000);//vector对象的.reserve()方法设置初始空间大小
	//每次读取文件中的一行直到结尾
	while(getline(ifs, line))//getline(ifs, string & line);
	{
		istringstream iss(line);//字符串输入流, 初始化为line
		while(iss >> word)//iss 中的string 输出给 word，以空格分隔
		{
			if(!((word[0]>=65&&word[0]<=90) || (word[0]>=97&&word[0]<=122)))
				continue;
			//auto这边不太懂，大概是迭代器,迭代器类似指针？
			auto it = _dict.begin();
			//_dict.begin()方法是干什么的？
			for(; it != _dict.end(); ++it)
			{
				if(it->word == word)
				{
					++(it->freq);
					break;
				}
			}
			//_dict.end()是空指针吗?
			if(it == _dict.end())
			{
				//vector 类的push_back()方法
				_dict.push_back(Record(word, 1));
			}
		}
	}
	//关闭输入文件流
	ifs.close();
	//sort
	std::sort(_dict.begin(), _dict.end());//不懂
}

void WordStatistic::writeFile(const string & filename)
{
	ofstream ofs;//ofs输出文件流对象
	ofs.open(filename.c_str());
	//以上两句可以用ofstream fos(filename); 一句代替
	if(!ofs.good())
	{
		cout << "ofstream open error!" << endl;
	}

	for(auto & elem : _dict)
	{
		ofs << elem.word << " " << elem.freq << endl;
	}

	ofs.close();
}

int main(void){
	WordStatistic wa;
	wa.readFile("The_Holy_Bible.txt");
	wa.writeFile("dictionary.dat");
	return 0;
}

