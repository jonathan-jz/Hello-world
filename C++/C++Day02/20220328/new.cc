#include <stdlib.h>
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;
 
void test0() 
{
	//malloc并不会进行初始化
	int * pint = (int*)malloc(sizeof(int));
	memset(pint, 0, sizeof(int));
	*pint = 10;

	cout << "*pint:" << *pint << endl;
	free(pint);

	//申请一个数组的空间
	int * pint2 = (int*)malloc(10 * sizeof(int));
	memset(pint2, 0, 10 *sizeof(int));
	for(int i = 0; i < 10; ++i) {
		pint2[i] = 1;
	}

	free(pint2);
} 

void test1()
{
	//new表达式是可以初始化
	int * pint = new int(10);
	cout << "*pint:" << *pint << endl;

	delete pint;

	//申请一个数组的空间
	int * pint2 = new int[10]();
	for(int i = 0; i < 10; ++i) {
		pint2[i] = 1;
	}

	for(int i = 0; i < 10; ++i) {
		cout << pint2[i] << " ";
	}
	cout << endl;

	//回收时，需要带上[]
	delete [] pint2;
}

int main(void)
{
	test0();
	test1();
	return 0;
}
