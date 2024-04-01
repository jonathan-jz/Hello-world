 ///
 /// @file    shortroad.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-04-05 11:18:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
void test0() 
{
	int a = 0, b = 2;
	//在逻辑与运算符左右两边的表达式都为真时，表达式才为真
	//如果左边的表达式为假，右边不再需要进行运算，
	//表达式整体就为假了
	if(a && b++) {
		cout << "两边都为真" << endl;
	} else {
		cout << "else部分 " << endl;
	}
	cout << "b:" << b << endl;
} 

void test1()
{
	int a = 1, b = 2;
	//在逻辑或运算符左边的表达式如果为真时，整个表达式的值
	//为真了， 右边的表达式不会再执行;
	if(a || b++) {
		cout << "if部分" << endl;
	} else {
		cout << "else部分 " << endl;
	}
	cout << "b:" << b << endl;

}
 
int main(void)
{
	/* test0(); */
	test1();
	return 0;
}
