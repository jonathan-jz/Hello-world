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

	Complex(const Complex & rhs)
	: _dreal(rhs._dreal)
	, _dimage(rhs._dimage)
	{
		cout << "Complex(const Compelx&)" << endl;
	}

	void print() const
	{
		cout << _dreal << " + " << _dimage << "i" << endl;
	}

	//返回值形式使用引用，就能满足需求了
	//不需要再进行复制
	Complex & operator+=(const Complex & rhs)
	{
		cout << "Complex operator+=(const Complex&)" << endl;
		this->_dreal += rhs._dreal;
		this->_dimage += rhs._dimage;
		return *this;
	}

private:
	//friend关键字不受public/private的影响
	friend Complex operator+(const Complex & lhs, const Complex & rhs);
	friend Complex & operator++(Complex & c);
	friend Complex operator++(Complex & c,int);

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

//前置++
Complex & operator++(Complex & c)
{
	cout << "Complex operator++(Complex&)" << endl;
	c._dreal++;
	c._dimage++;
	return c;
}

//后置++ 第二个参数只是为了与前置形式做一个区分
//必须要传参
Complex operator++(Complex & c,int)
{
	cout << "Complex operator++(Complex&,int)" << endl;
	Complex tmp(c);
	c._dreal++;
	c._dimage++;
	return tmp;
}


void test2()
{
	int a = 1;
	cout << "(++a) :" << (++a) << endl;
	cout << "a:" << a << endl;
	cout << "(a++) :" << (a++) << endl;
	cout << "a:" << a << endl;

	Complex c1(1, 2);
	cout << "(++c1):";
	(++c1).print();//前置++ 
	cout << "c1:";
	c1.print();
	cout << endl;

	cout << "(c1++):";
	(c1++).print();
	cout << "c1:";
	c1.print();
}

 
void test0() 
{
	int a = 1, b = 2;
	int c = a + b;//内置类型可以直接进行加法操作

	a += b;// a = a + b, 当该表达式执行完毕之后，a本身已经发生了变化


	Complex c1(1, 2), c2(3, 4);
	//但自定义类类型是不可以的
	Complex c3 = c1 + c2;//该表达式执行结束之后，c1/c2不变
	//上面的与下面的表达式是等价的
	Complex c4 = operator+(c1, c2);
	cout << "c3:";
	c3.print();
} 

void test1()
{
	Complex c1(1, 2), c2(3, 4);
	
	c1 += c2;// c1.operator+=(c2)
	cout << "c1:";
	c1.print();
}
 
int main(void)
{
	/* test0(); */
	/* test1(); */
	test2();
	return 0;
}
