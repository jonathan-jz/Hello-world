#include <iostream>
using std::cout;
using std::endl;


//宏定义的可读性不强, 维护性很差
#define MAX(x,y)  ((x)>(y)?(x):(y))
#define MULTIPLY(x,y) ((x)*(y))

//inine函数的不存在调用开销
inline
int Max(int x, int y)
{
	return x > y ? x : y;
}

void test1()
{
	int a = 3, b = 4;
	cout << Max(a,b) << endl;
	cout << Max(1 + 2, 3 + 4) << endl;
}
 
void test0() 
{
	int a = 3, b = 4;
	cout << MAX(a,b) << endl;
	printf("MAX(a,b): %d\n", MAX(a, b));

	cout << MULTIPLY(a,b) << endl;
	//如果发生错误时，会延迟到运行时
	cout << MULTIPLY(1+2,3+4) << endl;
} 
 
int main(void)
{
	test0(); 
	test1();
	return 0;
}
