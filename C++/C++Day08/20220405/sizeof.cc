 ///
 /// @file    sizeof.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-04-05 11:26:43
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
void test0() 
{
	int a = 1;
	printf("sizeof(a):%d\n", sizeof(a));//在编译时就计算完成
	printf("sizeof(a):%d\n", sizeof a);//ok
	//printf("sizeof(a):%d\n", sizeof int);
} 
 
int main(void)
{
	test0();
	return 0;
}
