#include <iostream>
using std::cout;
using std::endl;


int & getNumber()
{
	int * pint = new int(10);
	return *pint;
}

void test1()
{
	int a = 1, b = 2;
	int c = a + getNumber() + b + getNumber();
	cout << "c:" << c << endl;
}


 
void test0() 
{
	int a = 1, b = 2;
	int & number = getNumber();
	cout << "&a:" << &a << endl;
	cout << "&number:" << &number << endl;
	int c = a + b + number;
	cout << "c:" << c << endl;

	//要回收getNumber函数得到的堆空间
	delete (&number);
} 
 
int main(void)
{
	test0(); 
	test1();
	
	return 0;
}
