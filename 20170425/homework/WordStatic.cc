 ///
 /// @file    WordStatic.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-15 10:17:31
 ///
 
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istringstream;

struct Record
{
	Record(const string & w, int f)
	: word(w)
	, freq(f)
	{}

	bool operator <(const Record & rhs) const 
	{
		return this->word < rhs.word;
	}

	string word;
	int freq;
};




class WordStatic
{
public:
	void readFile(const string & filename);
	void writeFile(const string & filename);
private:
	vector<Record> _dict;
};


void WordStatic::readFile(const string & filename)
{
	ifstream ifs;
	ifs.open(filename.c_str());
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return ;
	}
	
	string line;
	string word;
	_dict.reserve(10000);
	while(getline(ifs, line))
	{
		istringstream iss(line);
		while(iss >> word)
		{
			auto it = _dict.begin();
			for(; it != _dict.end(); ++it)
			{
				if(it->word == word)
				{
					++(it->freq);
					break;
				}
			}
			
			if(it == _dict.end())
			{
				_dict.push_back(Record(word, 1));
			}
		}
	}
	ifs.close();

	//sort
	std::sort(_dict.begin(), _dict.end());
}
	
void WordStatic::writeFile(const string & filename)
{
	ofstream ofs(filename);
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


int main(void)
{
	WordStatic ws;
	ws.readFile("The_Holy_Bible.txt");
	ws.writeFile("dictionary.dat");

	return 0;
}
