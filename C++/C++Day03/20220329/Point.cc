#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	//构造函数的作用:初始化数据成员
	//构造函数可以重载
	Point()
	{	
		cout << "Point()" << endl;	
		_ix = 0;
		_iy = 0;
	}

	Point(int ix, int iy)
	{
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

	Point pt2(1, 2);
	cout << "pt2:";
	pt2.print();
} 
 
int main(void)
{
	test0();
	return 0;
}
