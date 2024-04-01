#include <unistd.h>

#include <iostream>
using std::cout;
using std::endl;
 
void test0() 
{
	//全缓冲
	for(int idx = 0; idx < 10; ++idx) {
		std::cerr << 'a';
	}
	//cout << endl;

	sleep(3);
 
} 

void test1()
{
	cout << "hello, cout" << endl;
	std::cerr << "hello, cerr" << endl;
	std::clog << "hello, clog" << endl;
}
 
//当程序退出时，会自动清空缓冲区
int main(void)
{
	test0();
	 test1(); 
	return 0;
}
