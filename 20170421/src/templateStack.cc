 ///
 /// @file    stack.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-21 21:22:51
 ///
 
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

//对于模板而言，只有类模板可以对模板参数设置默认参数（缺省参数）
template <typename T, int _size = 10>
class Stack
{
public:
	Stack();
	~Stack();

	void push(T num);
	void pop();
	bool full();
	bool empty();
	T top();
private:
	int _top;
	T * _arr;
};

template <typename T, int _size>
Stack<T, _size>::Stack()
: _top(-1)
, _arr(new T[_size])
{
}

template <typename T, int _size>
Stack<T, _size>::~Stack()
{
	delete [] _arr;
}

template <typename T, int _size>
bool Stack<T, _size>::full()
{
	return _top == _size - 1;
}

template <typename T, int _size>
bool Stack<T, _size>::empty()
{
	return _top == -1;
}

template <typename T, int _size>
void Stack<T, _size>::push(T elem)
{
	if (!full())
		_arr[++_top] = elem;
	else
		cout << "Stack is full " << endl;

}

template <typename T, int _size>
void Stack<T, _size>::pop()
{
	if(!empty())
		--_top;
	else
		cout << "Stack is empty " << endl;
}

template <typename T, int _size>
T Stack<T, _size>::top()
{
	return _arr[_top];
}

#if 0
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
#endif

int main(void)
{
	vector<string> vecstr;
	Stack<string> stack;
	cout << "at the begining, is stack empty? " << stack.empty() << endl;
	string s1(2, 'A');
	stack.push(s1);
	cout << "now, is stack empty? " << stack.empty() << endl;
	for (int idx = 1; idx != 11; ++idx)
	{
		string tmp(2, 'A' + idx);
		stack.push(tmp);
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
