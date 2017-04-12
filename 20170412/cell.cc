 ///
 /// @file    cell.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-12 21:16:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Cell
{
public:
	Cell(): f(b), g(d)
	{}
private:
	int a;
	char b;
	float c;
	double d;
	short e[5];
	char & f;
	double & g;
	static int h;

};

int main(void)
{
	cout << sizeof(Cell) << endl;

	return 0;
}
