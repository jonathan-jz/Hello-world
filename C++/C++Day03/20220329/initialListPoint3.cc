#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix) 
	, _iy(iy) 
	{//有参构造函数
		cout << "Point(int,int)" << endl;
		//不推荐以下写法
		//_ix = ix;//这是初始化操作么？
		//_iy = iy;//不是，仅仅是一个赋值操作
	}
	
	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	//
	~Point()
	{	cout << "~Point()" << endl;	}

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

	int a = 1;//这是初始化
	a = 2;//这是赋值操作
} 
 
int main(void)
{
	test0();
	return 0;
}
