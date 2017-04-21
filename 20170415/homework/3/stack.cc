 ///
 /// @file    stack.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-19 11:00:16
 ///
 
#include <iostream>
using std::cout;
using std::endl;
const int stack_len_max = 1024;
class Stack
{
public:
	Stack();
	~Stack();

	void push(int);
	void pop();
	int top();
	bool empty();
	bool full();
private:
	int _stack[stack_len_max];
	int _top;
};
