#include "add.hpp"
#include <iostream>
using std::cout;
using std::endl;
 
void test0() 
{
	int a = 3, b = 4;
	cout << "add(a, b):" << add(a, b) << endl;
} 
 
int main(void)
{
	test0();
	return 0;
}
