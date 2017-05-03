#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::auto_ptr;

int main(void)
{
	double * ap = new double(7.77);
	auto_ptr<double> apd(ap);
	cout << "*apd = " << *apd << endl;
	cout << "ap = " << ap << endl;
	cout << "adp'get() = " << apd.get() << endl;

	int * p1 = new int(10);
	auto_ptr<int> api(p1);
	auto_ptr<int> api2(api);//进行了复制，表达值语义
	//底层实现是将api托管的指针交给了api2，并把自己托管的指针置为NULL
	//本身存在缺陷，现在已经不再使用
	
	cout << "*api2 = " << *api2 << endl;
	cout << "*ap1 = " << *api << endl;//error, segment falt
	cout << "----" << endl;

	return 0;
}
