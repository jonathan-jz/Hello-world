#include <iostream>
using std::cout;
using std::endl;

int & func()
{
	int * p = new int (1);
	return *p;
	// int number = 1;
	// return number;
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
