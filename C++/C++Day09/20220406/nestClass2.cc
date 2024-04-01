 ///
 /// @file    nestClass.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-04-06 11:35:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 

//全局类
class Line
{
private:
	//内部类
	class Point  //Point类型为Line而生
	{
	public:
		Point(int ix = 0, int iy = 0)
		: _ix(ix)
		, _iy(iy)
		{}

		void print() const;

	private:
		int _ix;
		int _iy;
	};
public:

	Line(int x1, int y1, int x2, int y2)
	: _pt1(x1, y1)
	, _pt2(x2, y2)
	{	cout << "Line(int,int,int,int)" << endl;	}

	void printLine() const
	{
		_pt1.print();
		cout << " ---> ";
		_pt2.print();
		cout << endl;
	}

private:
	Point _pt1;
	Point _pt2;
};//end of class Line

void Line::Point::print() const
{
	cout << "(" << _ix
		 << "," << _iy
		 << ")";
}

void test0() 
{
	Line line(1, 2, 3, 4);
	line.printLine();


	//将Point放在Line的私有区域后，就不能
	//直接在Line之外创建Point对象了
	//Line::Point pt(11, 12);
	//pt.print();
} 
 
int main(void)
{
	test0();
	return 0;
}
