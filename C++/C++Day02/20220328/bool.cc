#include <iostream>
using std::cout;
using std::endl;
 
void test0() 
{
	bool b1 = true;
	bool b2 = false;
	bool b3 = 0;
	bool b4 = 1;
	bool b5 = -1;
	bool b6 = 100;

	cout << "sizeof(bool):" << sizeof(bool) << endl;

	cout << "b1:" << b1 << endl
		 << "b2:" << b2 << endl
		 << "b3:" << b3 << endl
		 
		 << "b4:" << b4 << endl
		 << "b5:" << b5 << endl
		 << "b6:" << b6 << endl;
 
} 
 
int main(void)
{
	test0();
	return 0;
}
