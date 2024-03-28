#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	//无参构造函数需要显式定义出来
	//系统不会再自动提供的
#if 0
	Point()
	{	
		cout << "Point()" << endl;	
		_ix = 0;
		_iy = 0;
	}
#endif

	//构造函数是特殊的成员函数
	//成员函数都可以设置默认值
	Point(int ix = 0, int iy = 0)
	{//有参构造函数
		cout << "Point(int,int)" << endl;
		_ix = ix;
		_iy = iy;
	}
	
	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

private:
	int _ix;
	int _iy;
};
 
void test0() 
{	//当创建一个对象时，会调用构造函数
	Point pt;//没有传递参数，调用的无参构造函数
	cout << "pt:";
	pt.print();

#if 1
	Point pt2(1, 2);
	cout << "pt2:";
	pt2.print();
#endif
} 
 
int main(void)
{
	test0();
	return 0;
}
