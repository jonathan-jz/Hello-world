 ///
 /// @file    anouymousNamespace.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-03-28 09:36:04
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;



int gnumber = 1;

namespace 
{

int number = 3;

}//end of namespace 


namespace wd
{

int number = 2;

void display()
{
	cout << "wd::display()" << endl;
	cout << "number:" << number << endl;
	cout << "全局变量gnumber:" << gnumber << endl;
	cout << "匿名命名空间中的变量number:" << ::number << endl;
	::printf("hello,world\n");//C语言的库函数可以认为就在匿名的命名空间中
}

}//end of namespace wd

 
void test0() 
{
	wd::display();
} 
 
int main(void)
{
	test0();
	return 0;
}
