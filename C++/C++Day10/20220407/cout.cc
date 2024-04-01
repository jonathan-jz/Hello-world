 ///
 /// @file    cout.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-04-07 09:39:40
 ///
 
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;


class Point
{
public:
	Point()
	: _ix(0)
	, _iy(0)
	{}

	//函数后面的=delete 代表的意思是
	//该函数从类中被删除了，不再提供
	Point(const Point & rhs) = delete;
	Point & operator=(const Point &) = delete;

private:
	int _ix;
	int _iy;
};

void test1()
{
	Point pt1;
	Point pt2 = pt1;//不能进行

	Point pt3;
	pt3 = pt1;//不能进行
}

 
void test0() 
{
	int num = 1;
	const char * pstr = "hello,world";

	cout << "num:" << num << endl;
	cout << pstr << endl;
	operator<<(cout, pstr);//普通函数形式
	cout << endl;

	cout.operator<<(pstr);//成员函数形式
	printf("pstr:%p\n", pstr);

	cout << sizeof(cout) << endl;
	cout << sizeof(cin) << endl;

	//std::ostream os = cout;
	ifstream ifs1;
	ifstream ifs2 = ifs1;//不能进行拷贝构造
	ifstream ifs3;
	ifs1 = ifs3;//不能赋值操作
} 
 
int main(void)
{
	test0();
	return 0;
}
