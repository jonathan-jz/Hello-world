#include <stdio.h>


#if 0
int add(int x)
{
	return x;
}

int add(int x, int y)
{
	return x + y;
}
#endif



int add(int x = 0, int y = 0, int z=0)
{
	return x + y + z;
}
 
int main(void)
{
	int a = 1, b = 3, c = 5;
	printf("add(a):%d\n", add(a));
	printf("add(a, b):%d\n", add(a, b));
	printf("add(a, b, c):%d\n",add(a, b, c));
	return 0;
}
