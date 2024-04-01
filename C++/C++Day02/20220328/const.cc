#include <iostream>
using std::cout;
using std::endl;

 
void test0() 
{
	const int number = 10;
	//number = 11; //这里的number不能被修改
	cout << "number:" << number << endl;
} 

void test1()
{
	// const int number;   //const一开始就应该被赋值，否则报错
	// cout << "number:" << number << endl;
}

//#define KMAX 1000
#define KMAX (500+500)
void test2()
{
	int a = 2, b = 3;
	int c = a * b * KMAX;
	cout << "c: " << c << endl;

	const int maxer = 1000;
	int d = a * b * maxer;
	cout << "d: " << d << endl;
}

 
int main(void)
{
	test0(); 
	cout<<"+++++++++++++++++++++++"<<endl;
	test1(); 
	cout <<"+++++++++++++++++++++++++++"<<endl;
	test2();

	return 0;
}
