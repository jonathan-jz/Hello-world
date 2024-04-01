 ///
 /// @file    Complex.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-04-05 11:03:49
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//复数
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

	//成员函数的形式重载
	Complex operator+(const Complex & rhs)
	{
		return Complex(this->_dreal + rhs._dreal,
					   this->_dimage + rhs._dimage);
	}


private:
	double _dreal;	//实部
	double _dimage; //虚部  i^2 == -1
};


 
void test0() 
{
	int a = 1, b = 2;
	int c = a + b;//内置类型可以直接进行加法操作

	Complex c1(1, 2), c2(3, 4);
	//但自定义类类型是不可以的
	Complex c3 = c1 + c2;//该表达式执行结束之后，c1/c2不变
	//上面的与下面的表达式是等价的
	Complex c4 = c1.operator+(c2);
	cout << "c3:";
	c3.print();
} 
 
int main(void)
{
	test0();
	return 0;
}
