 ///
 /// @file    overload.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-03-28 16:30:36
 ///
 
#include <stdio.h>

#ifdef __cplusplus   //C++编译器自带的一个宏定义
extern "C"
{
#endif
//需求：第一个add函数不希望被改编,即它的调用方式
//需要用C的方式进行调用
//由 extern "C" {} 大括号包围的代码都按C的方式进行调用

int add(int x, int y)
{
	return x + y;
}

#ifdef __cplusplus
}// end of extern "C"
#endif

int add(int x, double y)
{
	return x + y;
}

int add(double y, int x)
{
	return x + y;
}

int add(int x, int y, int z)
{
	return x + y + z;
}
 
int main(void)
{
	int a = 1, b = 3, c = 5;
	printf("add(a, b):%d\n", add(a, b));
	printf("add(a, b, c):%d\n",add(a, b, c));
	return 0;
}
