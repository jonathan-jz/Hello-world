 ///
 /// @file    reference.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-03-28 11:45:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
void test0() 
{
	int * pint = nullptr;//指针可以单独存在
	//int & ref = 1;
	int a = 1;
	int & ref = a;//引用一经初始化之后，
	//就与变量a是一样的, 
	//引用本质上是一个变量的别名

	cout << "a:" << a << endl;
	cout << "ref:" << ref << endl;
	ref = 10;
	cout << "修改之后:" << endl;
	cout << "a:" << a << endl;
	cout << "ref:" << ref << endl;
	cout << "&ref:" << &ref << endl;
	cout << "&a:" << &a << endl;
} 
 
int main(void)
{
	test0();
	return 0;
}
