 ///
 /// @file    test.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-03-28 09:55:28
 ///
 
#include <iostream>
using std::cout;
using std::endl;

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

 
//extern int number;

void test1()
{
	cout << "extern wd::inumber :" << wd::inumber << endl;
	//cout << "extern number: " << ::number << endl;
}





















