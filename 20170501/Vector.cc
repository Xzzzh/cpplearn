 ///
 /// @file    Vector.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-01 15:08:24
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;


template <typename T>
class Vector
{
public:
	Vector();
	~Vector();

	void push_back(const T & val);
	void pop_back();

	size_t size() const;
	size_t capacity() const;

	T & operator[](size_t idx);

private:
	void reallocate();//动态扩容

private:
	static std::allocator<T> _alloc;
	T * _elem;
	T * _first_free;
	T * _end;
};

template <typename T>
std::allocator<T> Vector<T>::_alloc;//在类之外进行初始化

template <typename T>
Vector<T>::Vector()
: _elem(0)
, _first_free(0)
, _end(0)
{
}


template <typename T>
Vector<T>::~Vector()
{
	while(size())
		_alloc.destroy(--_first_free);

	_alloc.deallocate(_elem, capacity());
}


template <typename T>
size_t Vector<T>::size() const
{
	return _first_free - _elem;
}

template <typename T>
size_t Vector<T>::capacity() const
{
	return _end - _elem;
}

template <typename T>
void Vector<T>::push_back(const T & val)
{
	size_t sz = size();
	size_t cap = capacity();

	if(sz == cap)
		reallocate();

	_alloc.construct(_first_free, val);
	++_first_free;
}

template <typename T>
void Vector<T>::pop_back()
{
	if(size())
		_alloc.destroy(--_first_free);//destroy只调用对象的析构函数
}

template <typename T>
T & Vector<T>::operator[](size_t idx)
{
	return *(_elem + idx);
}

template <typename T>
void Vector<T>::reallocate()
{
	size_t oldCap = capacity();
	size_t newCap = oldCap > 0 ? 2 * oldCap : 1;

	//先开辟未初始化对象的空间
	T * ptmp = _alloc.allocate(newCap);

	//复制元素
	std::uninitialized_copy(_elem, _first_free, ptmp);
	
	//销毁原空间中的元素
	while(_first_free != _elem)
		_alloc.destroy(--_first_free);

	//回收原来的空间
	_alloc.deallocate(_elem, oldCap);

	_elem = ptmp;
	_first_free = _elem + oldCap;
	_end = _elem + newCap;
}

void display(Vector<int> & vec)
{
	for(size_t idx = 0; idx != vec.size(); ++idx)
	{
		cout << vec[idx] << " ";
	}
	cout << endl;
}

void print(Vector<int> & vec)
{
	cout << "vec's size = " << vec.size() << endl;
	cout << "vec's capa = " << vec.capacity() << endl;
}

int main(void)
{
	Vector<int> vecInt;
	vecInt.push_back(1);
	print(vecInt);

	vecInt.push_back(2);
	print(vecInt);

	vecInt.push_back(3);
	print(vecInt);

	vecInt.push_back(4);
	print(vecInt);

	vecInt.push_back(5);
	print(vecInt);

	vecInt.push_back(6);
	print(vecInt);

	vecInt.push_back(7);
	print(vecInt);

	vecInt.push_back(8);
	print(vecInt);

	vecInt.push_back(9);
	print(vecInt);

	cout << endl;
	display(vecInt);

	return 0;

}
