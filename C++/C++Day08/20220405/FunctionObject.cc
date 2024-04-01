 ///
 /// @file    FunctionObject.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-04-05 15:47:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Foo
{
public:
	int add(int x,int y)
	{
		return x + y;
	}

	//重载了函数调用运算符的类创建的对象，都称为函数对象
	int operator()(int x, int y)
	{
		++_count;
		return x + y;
	}

	int operator()(int x, int y, int z)
	{
		++_count;
		return x + y + z;
	}

	int getCount() const {	return _count;	}

private:
	int _count = 0;//函数对象的状态
};

//add函数是一个无状态的函数
int add(int x, int y)
{
	return x + y;
}

int multiply(int x, int y)
{
	static int count = 0;
	++count;
	return x * y;
}

//如要定义一个函数对象，更多的是用struct关键字来实现
struct MyFunctor
{
	int operator()(int x, int y)
	{
		return x + y;
	}
};

 
void test0() 
{
	Foo foo;//foo是一个对象
	int a = 1, b = 2, c = 3;

	cout << foo(a, b) << endl;//函数对象
	cout << foo(a, b, c) << endl;
	cout << "foo::_count:" << foo.getCount() << endl;
	cout << add(a, b) << endl;

	Foo bar;
	cout << bar(a, b) << endl;
} 
 
int main(void)
{
	test0();
	return 0;
}
