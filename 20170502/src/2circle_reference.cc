#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::weak_ptr;
using std::shared_ptr;

class Parent;

class Child
{
public:
	Child(){	cout << "Child()" << endl;	}
	~Child(){	cout << "~Child()" << endl;	}

	shared_ptr<Parent> _parentPtr;

};

class Parent
{
public:
	Parent(){	cout << "Parent()" << endl;	}
	~Parent(){	cout << "~Parent()" << endl;	}

	shared_ptr<Child> _childPtr;
};

int main(void)
{
	shared_ptr<Child> child(new Child);
	shared_ptr<Parent> parent(new Parent);

	cout << "child's use_count() = " << child.use_count() << endl;
	cout << "parent's use_count() = " << parent.use_count() << endl;

	cout << endl;
	child->_parentPtr = parent;//引用计数加1
	parent->_childPtr = child;

	cout << "child's use_count() = " << child.use_count() << endl;
	cout << "parent's use_count() = " << parent.use_count() << endl;

	return 0;
}
