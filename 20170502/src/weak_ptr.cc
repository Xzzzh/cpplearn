 ///
 /// @file    weak_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-02 16:20:48
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;


class X
{
public:
	X()
	{	cout << "X()" << endl;	}

	~X()
	{	cout << "~X()" << endl;	}

	void display()
	{	cout << "X::display()" << endl;	}
};


int main(void)
{
	weak_ptr<X> p1;
	
	{
		shared_ptr<X> p2(new X);	
		cout << "p2's use_count() = " << p2.use_count() << endl;

		p1 = p2;//赋值
		cout << "p2's use_count() = " << p2.use_count() << endl;

		//p1->display();//weak_ptr是不能操作托管的对象
		shared_ptr<X> p3 = p1.lock();
		if(p3)
		{
			cout << "weak_ptr提升成功" << endl;
			p3->display();
		}
		else
		{
			cout << "weak_ptr提升失败,托管对象已经被销毁" << endl;
		}
	}
	cout << endl;

	shared_ptr<X> p4 = p1.lock();//weak_ptr知道托管是否还存在;如果存在，则提升成功；否则，提升失败
	if(p4)
	{
		cout << "weak_ptr提升成功" << endl;
		p4->display();
	}
	else
	{
		cout << "weak_ptr提升失败,托管对象已经被销毁" << endl;
	}
}

