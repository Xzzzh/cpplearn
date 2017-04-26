#include <ctype.h>
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

const int HASH_SIZE = 26;
using namespace std;

class WordStatic
{
public:
	void readFile(const string & filename);
	void writeFile(const string & filename);
private:
	map<string , int> _dirc[HASH_SIZE];
};

void WordStatic::readFile(const string & filename)
{
	ifstream ifs;
	ifs.open(filename.c_str());
	if (!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return;
	}
	string line;
	string word;
	int ans;
	while(getline(ifs, line))
	{
		istringstream iss(line);
		while(iss >> word)
		{
			if (!isalpha(word[0]))
				continue;
			ans = word[0] - 'a';
			_dirc[ans][word] += 1; 
//			cout << word << _dirc[word] << " " <<  endl;
		}
	}
	ifs.close();
}

void WordStatic::writeFile(const string & filename)
{
	ofstream ofs;
	ofs.open(filename.c_str());
	if (!ofs.good())
	{	
		cout << "ofstream open error!" << endl;
	}
	for (int i = 0; i < HASH_SIZE; ++i)
	{
		for (map<string, int>::iterator it = _dirc[i].begin(); it != _dirc[i].end(); ++it)
		{
			ofs << it->first << " " << it->second << endl;
		}
	}
	ofs.close();
}

int main(void)
{
	WordStatic ws;
	ws.readFile("./The_Holy_Bible.txt");
	ws.writeFile("hash_dict.dat");
	return 0;
}
