#include <iostream>
using std::cout;
using std::endl;

//值传递，各自有自己独立的栈空间
//当实参与形参进行结合之后，
//形参的操作与实参无关的
//
//值传递
#if 0
void swap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}
 
void test0() 
{
	int a = 1, b = 2;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	swap(a, b);
	cout << "经过修改之后:" << endl;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
} 
#endif


//地址传递 => 本质还是值传递
void swap(int * px, int * py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}

void test1() 
{
	int a = 1, b = 2;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	swap(&a, &b);
	cout << "经过修改之后:" << endl;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
} 

//引用传递

void swap(int & x, int & y)
{
	int temp = x;
	x = y;
	y = temp;
}

void test2() 
{
	int a = 1, b = 2;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	swap(a, b);
	cout << "经过修改之后:" << endl;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
} 

void test3()
{
	int a = 2;
	//非const引用
	int & ref = a;

	//const引用也不能修改变量的值
	const int & ref2 = 1;
	//ref2 = 10;

}
 
int main(void)
{
	/* test0(); */
	/* test1(); */
	test2();
	return 0;
}
