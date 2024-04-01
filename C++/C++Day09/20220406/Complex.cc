 ///
 /// @file    ioOperator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-04-05 17:48:17
 ///
 
#include <iostream>
#include <limits>
using std::cout;
using std::endl;

class Point;
class Complex
{
public:
	//explicit
	Complex(const Point & rhs);

	Complex(double dreal, double dimage = 0)
	: _dreal(dreal)
	, _dimage(dimage)
	{
		cout << "Complex(double, double)" << endl;
	}


	//类型转换函数
	operator double()
	{	
		cout << "operator double()" << endl;
		return _dreal ;	
	}

	operator Point();


	void print() const
	{
		cout << _dreal << " + " << _dimage << "i" << endl;
	}

	//友元函数
	friend std::ostream & operator<<(std::ostream & os, const Complex & rhs);
	friend std::istream & operator>>(std::istream & is, Complex & rhs);
private:
	friend Complex operator+(const Complex & lhs, const Complex & rhs);

	double _dreal;	//实部
	double _dimage; //虚部  i^2 == -1
};


//友元函数形式重载, 友元函数本身是一个普通函数
//参数形式都为const的, 因为执行之后参数是保持不变的
Complex operator+(const Complex & lhs, const Complex & rhs)
{
	return Complex(lhs._dreal + rhs._dreal,
				   lhs._dimage+ rhs._dimage);
}

std::ostream & operator<<(std::ostream & os, const Complex & rhs)
{
	os << rhs._dreal << " + " << rhs._dimage << "i" << endl;
	return os;
}

void readDouble(std::istream & is, double & number)
{
	while(is >> number, !is.eof())
	{
		if(is.bad()) {
			cout << "istream has broken!" << endl;
			return;
		} else if(is.fail()) {
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "pls input a valid double number:" << endl;
		} else {
			break;
		} 
	}
}

std::istream & operator>>(std::istream & is, Complex & rhs)
{
	readDouble(is, rhs._dreal);
	readDouble(is, rhs._dimage);

	return is;
}
 

class Point
{
	friend class Complex;
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{}

	friend std::ostream & operator<<(std::ostream &os, const Point & rhs);

private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream &os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

Complex::Complex(const Point & rhs)
: _dreal(rhs._ix)
, _dimage(rhs._iy)
{
	cout << "Complex(const Point&)" << endl;
}

//类型转换函数
Complex::operator Point()
{
	cout << "operator Point()" << endl;
	return Point(_dreal, _dimage);
}

void test0() 
{
	Complex c1(1, 2), c2(3, 4);
	cout << "c1:" << c1 << endl;
	//由其他类型向自定义类型转换
	//由构造函数来完成
	Complex c3 = 1.1;//隐式转换
	cout << "c3:" << c3 << endl;

	Point pt(11, 12);
	cout << "pt:" << pt << endl;
	//将一个Point类型的对象转换为Complex的对象
	Complex c4 = pt;//已经违反常规思维, 尽量少用或者不用
	cout << "c4:" << c4 << endl;
} 

void test1()
{
	Complex c1(11.11, 22);
	int x = c1;//将自定类类型向其他类型(int)转换
	cout << "x:" << x << endl;

	Point  pt(2, 3);
	pt = c1;//将自定类类型向其他类型(Point)转换
	cout << "pt:" << pt << endl;
}
 
int main(void)
{
	/* test0(); */
	test1();
	return 0;
}
