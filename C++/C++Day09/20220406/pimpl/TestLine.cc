 ///
 /// @file    TestLine.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-04-06 11:55:22
 ///
 
#include "Line.hpp"
#include "Line.hpp"

#include <iostream>
using std::cout;
using std::endl;
 
void test0() 
{
	Line line(1, 2, 3, 4);
	line.printLine();
} 
 
int main(void)
{
	test0();
	return 0;
}
