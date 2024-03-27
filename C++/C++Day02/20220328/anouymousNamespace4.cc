#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

int number = 3;
// //全局变量gnumber 可以作为外部变量使用
// int gnumber = 1;

// namespace 
// {
// 	int number = 3;
// }//end of namespace 


namespace wd
{
void display()
{
	cout << "wd::display()" << endl;
	cout << "匿名命名空间中的变量number:" << ::number << endl;
	printf("&::number: %p\n", &::number);
	//printf("&gnumber:%p\n", &gnumber);
}

int inumber = 4;

}//end of namespace wd

 
// void test0() 
// {
// 	wd::display();
// } 

void test1();
 
int main(void)
{
	//test0();
	test1(); 
	return 0;
}
