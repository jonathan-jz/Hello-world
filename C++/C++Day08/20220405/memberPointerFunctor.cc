 ///
 /// @file    memberPointerFunctor.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-04-05 16:04:31
 ///
 
#include <iostream>
using std::cout;
using std::endl;


//函数类型是由返回值和参数列表来定义
//所以display与print函数类型是相同的
//
void display()
{
	cout << "display()" << endl;
}

void print()
{
	cout << "print()" << endl;
}

//对于一个参数是无参的，返回值为void的
//函数进行重命名，为Function
typedef void(*Function)();

 
void test0() 
{
	void(*p)() = display;
	p();
	p = print;
	p();

	Function f = display;
	f();//函数对象

	f = print;
	f();
} 


class Foo
{
public:
	int add(int x, int y)
	{
		return x + y;
	}

	int multiply(int x, int y) 
	{
		return x * y;
	}
};

#if 1
int add(int x, int y)
{
	return x + y;
}
#endif

//成员函数指针
typedef int (Foo::*Funcpointer)(int,int);

void test1()
{
	//对于成员函数指针赋值时，传递过来的
	//成员函数名必须要加上类作用域，并在
	//其前面必须加上& 取地址符号
	Funcpointer fp = &Foo::add;
	//cout << fp(1, 2) << endl;
	//Funcpointer fp2 = Foo::add;
	//成员函数的调用是要通过对象(指针)进行的
	Foo foo;
	cout << (foo.*fp)(1, 2) << endl;

	//通过对象指针来调用成员函数指针
	Foo * pf = &foo;
	cout << (pf->*fp)(1, 2) << endl;

	fp = &Foo::multiply;
	cout << (foo.*fp)(3, 4) << endl;
	cout << (pf->*fp)(3, 4) << endl;
}

 
int main(void)
{
	test1();
	/* test0(); */
	return 0;
}
