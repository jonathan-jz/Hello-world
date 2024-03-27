#include <iostream>
using std::cout;
using std::endl;

int func()
{
	int number = 1;
	cout << "func() number:" << number << endl;
	return number;//发生复制
}

int arr[5] = {1, 2, 3, 4, 5};

//返回值为引用，这里没有发生复制
//提升程序的执行效率
int & getElement(int idx)
{
	return arr[idx];
}
 
void test0() 
{
	cout << getElement(0) << endl;
	//getElement函数返回时没有发生复制
	getElement(0) = 10;
	cout << "arr[0]:" << arr[0] << endl;
} 
 
int main(void)
{
	test0();
	return 0;
}
