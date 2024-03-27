#include <iostream>
using std::cout;
using std::endl;
 
void test0() 
{
	double val1 = 11.11;
	int val2 = (int)val1;
	int val3 = int(val1);

	cout << "val2:" << val2 << endl
		 << "val3:" << val3 << endl;
} 

void test1()
{
	double val1 = 11.11;
	int val2 = static_cast<int>(val1);
	cout << "val2:" << val2 << endl;

	//把一个void*的类型转换为int*
	double* pint = static_cast<double*>(malloc(sizeof(int)));
	*pint = 1;
}
 
int main(void)
{
	test0(); 
	test1();
	return 0;
}
