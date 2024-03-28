#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	//系统会自动提供一个拷贝构造函数
	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		//cout << "Point(const Point &)" << endl;
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
{	
	int a = 1;//
	int b = a;//复制

	//Point pt0();//这是一个函数声明
	//pt0.print();

	Point pt;//没有传递参数，调用的无参构造函数
	cout << "pt:";
	pt.print();

	Point pt2 = pt;//完成了对象的复制
	cout << "pt2:";
	pt2.print();

	//    Point(const Point &);//拷贝构造函数
	Point pt3(pt);//效果相同
	cout << "pt3:";
	pt3.print();
}

 
int main(void)
{
	test0();
	return 0;
}
