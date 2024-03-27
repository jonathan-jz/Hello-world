#include <iostream>
using std::cout;
using std::endl;
 
void test0() 
{
	const int number = 1;
	//int * p = &number;//error, 如果该操作被允许
	//*p = 10;//就可以修改number的值了
 
} 
 
void test1() 
{
	const int number = 1;
	const int * p = &number;//

	int *p2 = const_cast<int*>(&number);
	*p2 = 10;
	cout << "*p2: " << *p2 << endl;
	cout << " number:" << number << endl;
	cout << "p2:" << p2 << endl
		 << "&number:" << &number << endl;
 
} 

int main(void)
{
	test1();
	/* test0(); */
	return 0;
}
