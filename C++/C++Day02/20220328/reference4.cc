 ///
 /// @file    reference4.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-03-28 15:14:25
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int & func()
{
	int number = 1;
	return number;
}
 
void test0() 
{
	cout << "func():" << func() << endl;
} 
 
int main(void)
{
	test0();
	return 0;
}
