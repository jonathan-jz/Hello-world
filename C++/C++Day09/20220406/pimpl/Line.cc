 ///
 /// @file    Line.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-04-06 11:49:37
 ///
 
#include "Line.hpp"
#include <iostream>
using std::cout;
using std::endl;


//内部类
class Line::LineImpl
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

	LineImpl(int x1, int y1, int x2, int y2)
	: _pt1(x1, y1)
	, _pt2(x2, y2)
	{	cout << "LineImpl(int,int,int,int)" << endl;	}

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

void Line::LineImpl::Point::print() const
{
	cout << "(" << _ix
		 << "," << _iy
		 << ")";
}


Line::Line(int x1,int y1,int x2, int y2)
: _pimpl(new LineImpl(x1, y1, x2, y2))
{
	cout << "Line(int,int,int,int)" << endl;
}
Line::~Line()
{
	if(_pimpl) {
		delete _pimpl;
		_pimpl = nullptr;
	}
	cout << "~Line()" << endl;
}

void Line::printLine() const
{
	_pimpl->printLine();
}
