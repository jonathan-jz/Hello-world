#include <iostream>
using std::cout;
using std::endl;

 
void test0() 
{
	const int number = 10;
	//number = 11;
	cout << "number:" << number << endl;
} 

void test1()
{
	//const int number;
	//cout << "number:" << number << endl;
}

//#define KMAX 1000
#define KMAX (500+500)
void test2()
{
	int a = 2, b = 3;
	int c = a * b * KMAX;
	cout << "c: " << c << endl;

	const int maxer = 1000;
	int d = a * b * maxer;
	cout << "d: " << d << endl;
}

 
int main(void)
{
	/* test0(); */
	/* test1(); */
	test2();
	return 0;
}
