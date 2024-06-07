#include <stdio.h>

int add(int x, int y)
{
	return x + y;
}
 
int main(void)
{
	int a = 1, b = 3, c = 5;
	printf("add(a, b):%d\n", add(a, b));
	return 0;
}
