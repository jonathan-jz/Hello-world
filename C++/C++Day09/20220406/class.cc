 ///
 /// @file    class.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-04-06 11:27:44
 ///
 
#include <iostream>
using std::cout;
using std::endl;


int number = 1;

namespace wd
{

int number = 2;

//全局类
class Example
{
public:
	void display(int number)
	{
		cout << "全局变量number:" << ::number << endl;
		cout << "wd::number: " << wd::number << endl;
		cout << "类内部的number:" << this->number << endl;
		cout << "类内部的number:" << Example::number << endl;
		//就近原则，发生了"屏蔽"现象
		cout << "局部变量number:" << number << endl;
	}

private:
	int number = 3;
};


}//end of namespace wd

 
void test0() 
{
	wd::Example e;
	e.display(10);
} 
 
int main(void)
{
	test0();
	return 0;
}
