 ///
 /// @file    nestTemplate.cc
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-21 21:12:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//类模板里可以嵌套函数模板
template <typename T1>
class Test
{
public:
	template <typename T2>
	T2 convert(T1 data);
		
};

template <typename T1>
template <typename T2>
T2 Test<T1>::convert(T1 data)
{
	return (T2)data;
//	return static_cast<T2>(data);
}

int main(void)
{
	double d = 3.3;
	Test<double> test;
	cout << test.convert<int>(d) << endl;
	return 0;
}
