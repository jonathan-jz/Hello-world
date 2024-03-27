#include <iostream>
using std::cout;
using std::endl;
extern int number;
namespace wd
{
extern int inumber;
}

#if 0
namespace 
{
extern int number;
}
#endif




void test1()
{
	cout << "extern wd::inumber :" << wd::inumber << endl;
	cout << "extern number: " << ::number << endl;
}























