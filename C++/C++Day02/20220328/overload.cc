#include <stdio.h>


int add(int x, int y)
{
	return x + y;
}

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
