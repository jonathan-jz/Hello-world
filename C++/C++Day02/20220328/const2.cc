#include <iostream>
using std::cout;
using std::endl;
 
void test0() 
{
	int a = 1, b = 2;
	int* pa = &a;

	*pa = 10;//修改所值变量的值
	pa = &b;//改变pa指针的指向

	cout << "*pa:" << *pa << endl
		 << "pa：" << pa << endl
		 <<"a = "<<a<<endl;
} 


//常量指针  vs  指针常量
//int(*pf)()    int *()
//函数指针  vs  指针函数
//int (*p)[10]     int * p[10]
//数组指针  vs  指针数组


void test1() 
{
	int a = 1, b = 2;
	int const * pa = &a;//常量指针

	//*pa = 10;//error, 修改所值变量的值
	pa = &b;//改变pa指针的指向

	cout << "*pa:" << *pa << endl
		 << "pa：" << pa << endl;
} 

void test2() 
{
	int a = 1, b = 2;
	int * const pa = &a;//指针常量

	*pa = 10;//修改所值变量的值
	//pa = &b;//error, 改变pa指针的指向

	cout << "*pa:" << *pa << endl
		 << "pa：" << pa << endl
		 <<"*pa:"<<*pa<<endl;
} 

void test3() 
{
	int a = 1, b = 2;
	//两者都不能进行修改的情况
	const int * const pa = &a;//指针常量

	//*pa = 10;//error,修改所值变量的值
	//pa = &b;//error, 改变pa指针的指向

	cout << "*pa:" << *pa << endl
		 << "pa：" << pa << endl;
} 
 
int main(void)
{
	test0();
	test1();
	test2();
	test3();
	return 0;
}
