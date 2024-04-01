 ///
 /// @file    friend1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-04-05 09:58:09
 ///

#include <math.h>

#include <iostream>
using std::cout;
using std::endl;

class Point;//类的前向声明
class Line
{
public:
	//在函数声明中，是不需要知道Point的具体内容的
	//此时可以给出该类的前向声明形式
	double getDistance(const Point & lhs, const Point & rhs);
};

class Point
{
public:
	//友元之成员函数
	friend double Line::getDistance(const Point & lhs, const Point & rhs);

	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	void print() const 
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")";
	}

private:
	int _ix;
	int _iy;
};


double Line::getDistance(const Point & lhs, const Point & rhs)
{
	return sqrt((lhs._ix - rhs._ix) * (lhs._ix - rhs._ix) + 
				(lhs._iy - rhs._iy) * (lhs._iy - rhs._iy));
}
 
void test0() 
{
	Point pt1(1, 2), pt2(3, 4);
	cout << "pt1:";
	pt1.print();
	cout << " ---> pt2:";
	pt2.print();

	Line line;
	cout << "的距离:" << line.getDistance(pt1, pt2) << endl;
} 
 
int main(void)
{
	test0();
	return 0;
}
