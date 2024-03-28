#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

//完成了一个类的定义
struct Computer
{//大括号内部称为类内部
//public:
	//类的操作 => 类的成员函数
	void setBrand(const char * brand)
	{
		strcpy(_brand, brand);	
	}

	void setPrice(double price)
	{
		_price = price;
	}

	void print()
	{
		cout << "品牌:" <<  _brand << endl
			 << "价格:" << _price << endl;
	}

//private:
	//类的属性 => 类的数据成员
	char _brand[20];
	double _price;
};
 
void test0() 
{
	Computer c1;//创建对象
	c1.setBrand("小米");
	c1.setPrice(7777);
	c1.print();
	c1._price = 8888;
} 
 
int main(void)
{
	test0();
	return 0;
}
