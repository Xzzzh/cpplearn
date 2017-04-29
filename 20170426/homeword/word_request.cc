
#include <iostream>
#include <iterator>
#include <fstream>
#include <ctype.h>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

class WordRequest
{
public:
	WordRequest()
	: _wordfreq(0)
	, _word("")
	, _opensuccess(false)
	{}
	void readFile();
	void questResult();
private:
	void quest(ifstream &);
	string & wordhandle(string &);
private:
	map<int, string> _reaust;
	string _word;
	int _wordfreq;
	bool _opensuccess;
};

void WordRequest::readFile()
{
	string filename;
	cout << "Inpute filename:";
	cin >> filename; 
	ifstream ifs;
	ifs.open(filename.c_str());
	if (!ifs.good())
	{
		cout << "file open error!" << endl;
		return;
	}
	_opensuccess = true;
	cout << "Inpute word:";
	cin >> _word; 
	transform(_word.begin(), _word.end(), _word.begin(), ::tolower); 
	quest(ifs);
	ifs.close();
}

void WordRequest::quest(ifstream & ifs)
{
	string line;
	string word;
	int lineNum = 1;
	while(getline(ifs, line))
	{
		istringstream iss(line);
		while(iss >> word)
		{
			if (_word == wordhandle(word))
			{
				_reaust[lineNum] = line;
				++_wordfreq;
			}
		}
		++lineNum;
	}
}

void WordRequest::questResult()
{
	if (!_opensuccess)
		return;
	if (_wordfreq == 0)
	{
		cout << "No such word" << endl;
	}
	else
	{
		cout << "The \"" << _word << "\" occurs " << _wordfreq << " times" << endl;
		for (map<int, string>::iterator it = _reaust.begin();
				it != _reaust.end();
				++it)
		{
			cout << "[line:" << it->first << "] " << it->second << endl;
		}
	}
}

string & WordRequest::wordhandle(string & word)
{
	transform(word.begin(), word.end(), word.begin(), ::tolower); 
	if (!isalpha(word[0]))
	{
		word = word.substr(1);
	}
	return word;
}
int main(void)
{
	WordRequest wr;
	wr.readFile();
	wr.questResult();
	return 0;
}
