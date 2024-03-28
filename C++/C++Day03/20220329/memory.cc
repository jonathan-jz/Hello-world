#include <string.h>

#include <iostream>
using std::cout;
using std::endl;
 
void test0() 
{
	printf("test0:\n");
	int number = 1;
	//字符数组
	char str1[] = "hello,world";//还包含一个空字符'\0'
	//常量指针
	const char * pstr2 = "hello,wuhan";

	printf("str1: %s\n", str1);
	int len1 = strlen(str1);//11
	int len2 = sizeof(str1);//12
	printf("len1:%d, len2: %d\n", len1, len2);
	int len3 = strlen(pstr2);//11
	int len4 = sizeof(pstr2);// 8  64位系统中一个指针占据8个字节
	printf("len3:%d, len4: %d\n", len3, len4);
} 

int global = 100;
//全局/静态区
static int staticNumber = 1;

void test1()
{
	printf("test0:\n");
	int number = 1;
	//字符数组, 位于栈上
	char str1[] = "hello,world";//还包含一个空字符'\0'
	printf("&str1[0]: %p\n", &str1[0]);
	//常量指针
	const char * pstr2 = "hello,wuhan";
	//*pstr2 = 'X';//error

	int * pint = (int*)malloc(sizeof(int));

	//局部静态变量与全局静态变量有什么区别？
	static int staticNumber2 = 2;//全局/静态区
	++staticNumber2;
	printf("staticNumber2: %d\n", staticNumber2);

	printf("&number: %p\n", &number);
	printf("str1: %p\n", str1);
	printf("&pstr2: %p\n", &pstr2);
	printf("pstr2: %p\n", pstr2);
	printf("pint:%p\n", pint);
	printf("&pint:%p\n", &pint);
	printf("&global:%p\n", &global);//全局变量的位置在堆空间之下
	printf("&test1: %p\n", &test1);

	printf("&staticNumber: %p\n", &staticNumber);
	printf("&staticNumber2: %p\n", &staticNumber2);
}
 
int main(void)
{
	test0(); 
	cout << "++++++++++++++++++++++++++"<<endl;
	test1();
	/* test1(); */
	return 0;
}
