#include <iostream>
using std::cout;
using std::endl;

//对于一个空类，系统已经自动提供了四个函数
//默认构造函数
//拷贝构造函数
//赋值运算符函数
//析构函数
class Empty
{
};
 
void test0() 
{
	cout << "sizeof(Empty):" << sizeof(Empty) << endl;
	Empty e1;
	Empty e2;
	//如何判断两个对象是不同的对象?
	//答: 通过在内存中的地址
	cout << "&e1:" << &e1 << endl;
	cout << "&e2:" << &e2 << endl;

	Empty e3 = e1;

	e3 = e2;

	cout << "&e3:" << &e3 << endl;
} 
 
int main(void)
{
	test0();
	return 0;
}
