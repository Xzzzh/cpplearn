#include <iostream>
using std::cout;
using std::endl;

class Base
{
protected:
	Base(int ix = 0)
	: _ix(ix)
	{
		cout << "Base(int)" << endl;
	}
public:
	void display()
	{
		cout << "Base::_ix = " << _ix << endl;
	}
private:
	int _ix;
};

class Child : public Base
{
public:
	Child(int ix) : Base(ix)
	{
		cout << "Child(int)" << endl;
	}
};

int main(void)
{
	Base * p = new Child(1);
	p->display();

	return 0;
}
