 ///
 /// @file    bible.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-13 22:09:49
 ///
 
#include <string.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

class Word
{
public:
	Word()
	: _word("THEBEGIN")
	, _freq(111111111) 
	{
	
	}
		
	Word(string word)
	: _word(word)
	, _freq(1) 
	{

	}

	Word(const Word & word)
	: _word(word._word)
	, _freq(word._freq)
	{
	}

public:
	bool word_quest(string word)
	{
		if(_word == word)
			return true;
		else
			return false;
	}
	void freq_plus()
	{
		_freq += 1;
	}

public:
	string _word;
	int _freq;
};

int main(void)
{
	ifstream ifs("./The_Holy_Bible.txt");
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return -1;
	}
	

	ofstream ofs("dictionary.txt");
	if(!ofs.good())
	{
		cout << "ofstream open error!" << endl;
		return -1;
	}

	vector<Word> vecWord;
	vecWord.resize(1);

	vector<string> vecStr;
	vecStr.resize(100);
	string str;
	while(ifs >> str)
	{
		
		if (!((str[0] >= 65 && str[0] <=90) || (str[0] >= 97 && str[0] <=122)))
			continue;
		cout << "vecWord.capacity() == " << vecWord.capacity() << endl;
		cout << "vecWord.size() == " << vecWord.size() << endl;
		for(int i = 0; i < (int)vecWord.size(); ++i)	
		{
			if ((i == (int)vecWord.size() - 1) && !vecWord[i].word_quest(str))
			{
				cout << str << "add to vecWord"<< endl;
				vecWord.push_back(str);	
				cout << "break" << endl;
				break;
			}
			if (vecWord[i].word_quest(str))	
			{
				cout << str << "freq_plus()"<< endl;
				vecWord[i].freq_plus();
				cout << "break" << endl;
				break;
			}
		}
	}
	for (int j = 0; j < (int)vecWord.size(); ++j)
	{
		cout << vecWord[j]._word << " " << vecWord[j]._freq << endl;
		ofs << vecWord[j]._word << " " << vecWord[j]._freq << endl; 
	}


	ifs.close();
	ofs.close();
	return 0;
}
