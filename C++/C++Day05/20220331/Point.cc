#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	//当构造函数的形式中有一个参数时，
	//要确定一下，是否允许隐式转换执行
	//一般情况下，都要设置为explicit
	//禁止隐式转换
	explicit 
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
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
	//左边是Point类型，
	//右边时int类型
	//这里发生了隐式转换, 该转换是通过构造函数完成的
	//在这里不需要这种转换
	Point pt = 1;// Point(1);

	Point pt2(1, 2);//显示调用
	Point pt3(1);//显示调用

	cout << "pt:";
	pt.print();
}

int main(void)
{
	test0();
	return 0;
}

