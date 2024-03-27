#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;


//全局变量number 可以作为外部变量使用
int number = 1;

namespace 
{
int number = 3;
}//end of namespace 


namespace wd
{
void display()
{
	cout << "wd::display()" << endl;

	cout << "匿名命名空间中的变量number:" << ::number << endl;
	
}

}//end of namespace wd

 
void test0() 
{
	wd::display();
} 
 
int main(void)
{
	test0();
	return 0;
}


// #include <iostream>

// using std::cout;
// using std::endl;

// //全局变量number 可以作为外部变量使用
// int number = 1;

// namespace 
// {
//     int number = 3;
// } // end of anonymous namespace

// namespace wd
// {
//     void display()
//     {
//         cout << "wd::display()" << endl;
//         cout << "匿名命名空间中的变量number:" << number << endl; // 访问匿名命名空间中的number
//     }
// } // end of namespace wd

// void test0() 
// {
//     wd::display();
// } 

// int main(void)
// {
//     test0();
//     return 0;
// }
