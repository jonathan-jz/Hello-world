 ///
 /// @file    friend1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-04-05 09:58:09
 ///

#include <math.h>

#include <iostream>
using std::cout;
using std::endl;


class Point
{
public:
	//友元之普通函数(自由函数)
	friend double getDistance(const Point & lhs, const Point & rhs);

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

double getDistance(const Point & lhs, const Point & rhs)
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

	cout << "的距离:" << getDistance(pt1, pt2) << endl;
} 
 
int main(void)
{
	test0();
	return 0;
}
