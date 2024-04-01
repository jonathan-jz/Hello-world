 ///
 /// @file    ioOperator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-04-05 17:48:17
 ///
 
#include <iostream>
#include <limits>
using std::cout;
using std::endl;

class Complex
{
public:
	Complex(double dreal, double dimage)
	: _dreal(dreal)
	, _dimage(dimage)
	{
		cout << "Complex(double, double)" << endl;
	}

	void print() const
	{
		cout << _dreal << " + " << _dimage << "i" << endl;
	}

	//对于输入输出流运算符而言，不能以成员函数形式重载
	//否则与常规写法不一致
#if 0
	std::ostream & operator<<(std::ostream &os)
	{
		os << _dreal << " + " << _dimage << "i" << endl;
		return os;
	}
#endif

	//友元函数
	friend std::ostream & operator<<(std::ostream & os, const Complex & rhs);
	friend std::istream & operator>>(std::istream & is, Complex & rhs);
private:
	//friend关键字不受public/private的影响
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
 
void test0() 
{

	int a = 1, b = 2;
	cout << a << b << endl;
	//左操作数必须是流对象，由操作数才是其他类型 ostream&
	//operator<<(cout, a);

	//operator<<(operator<<(operator<<(cout, a), b), endl);
 
	Complex c1(1, 2), c2(3, 4);
	cout << "c1:" << c1 << endl;
	//cout << c1;
	//c1.operator<<(cout);// c1 << cout
	
	
	std::cin >> c1;
	cout << "c1:" << c1 << endl;
} 
 
int main(void)
{
	test0();
	return 0;
}
