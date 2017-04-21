 ///
 /// @file    stack.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-21 21:22:51
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Stack
{
public:
	Stack(int size)
	: _size(size)
	, _top(-1)
	, _arr(new int[_size])
	{}

	~Stack()
	{
		delete [] _arr;
	}

	void push(int num)
	{
		if(!full())
			_arr[++_top] = num;
		else
			cout << "Stack is full" << endl;
	}

	void pop()
	{
		if(!empty())
			--_top;
		else
			cout << "Stack is empty" << endl;
	}

	bool full()
	{
		return _top == (_size - 1);
	}

	bool empty()
	{
		return _top == -1;
	}

	int top()
	{
		return _arr[_top];
	}
private:
	int _size;
	int _top;
	int * _arr;
};

int main(void)
{
	Stack stack(10);
	cout << "at the begining, is stack empty? " << stack.empty() << endl;
	stack.push(1);
	cout << "now, is stack empty? " << stack.empty() << endl;
	for(int idx = 2; idx != 13; ++idx)
	{
		stack.push(idx);
	}
	cout << "now, is stack full? " << stack.full() << endl;
	while(!stack.empty())
	{
		cout << stack.top() << endl;
		stack.pop();
	}
	cout << "now, is stack empty? " << stack.empty() << endl;

	return 0;
}
