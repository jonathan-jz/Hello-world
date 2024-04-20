 ///
 /// @file    anouymousNamespace.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-03-28 09:36:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;


int number = 1;

namespace wd
{

int number = 2;

void display()
{
	cout << "wd::display()" << endl;
	cout << "number:" << number << endl;
	cout << "全局变量number:" << ::number << endl;
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
