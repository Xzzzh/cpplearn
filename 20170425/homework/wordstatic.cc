#include <ctype.h>
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class WordStatic
{
public:
	void readFile(const string & filename);
	void writeFile(const string & filename);
private:
	map<string , int> _dirc;
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
	while(getline(ifs, line))
	{
		istringstream iss(line);
		while(iss >> word)
		{
			if (!isalpha(word[0]))
				continue;
			_dirc[word] += 1; 
			cout << word << _dirc[word] << " " <<  endl;
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

	for (map<string, int>::iterator it = _dirc.begin(); it != _dirc.end(); ++it)
	{
		ofs << it->first << " " << it->second << endl;
	}
	ofs.close();
}

int main(void)
{
	WordStatic ws;
	ws.readFile("./The_Holy_Bible.txt");
	ws.writeFile("dict.dat");
	return 0;
}
