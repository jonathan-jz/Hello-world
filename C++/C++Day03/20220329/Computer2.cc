#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

//完成了一个类的定义
class Computer
{//大括号内部称为类内部
public:
	//类的操作 => 类的成员函数的声明
	//在public区域定义的函数称为
	//该类对外提供的接口、功能、服务
	//放到类的开头部分
	void setBrand(const char * brand);
	void setPrice(double price);
	void print();

private://该类需要隐藏的部分,尽量放到
		//类的尾部来
	//类的属性 => 类的数据成员
	char _brand[20];
	//double _price;
	double price_;
	double m_price;
	
};
 
void test0() 
{
	Computer c1;//创建对象
	c1.setBrand("小米");//都是在类之外执行的
	c1.setPrice(7777);
	//c1._price = 8888;
	c1.print();

} 
 
void Computer::setBrand(const char * brand)
{//对于在类之外实现的成员函数，由于有了
 //类作用域的保护, 也是在类内部
	strcpy(_brand, brand);	
}

void Computer::setPrice(double price)
{
	price_ = price;
}

void Computer::print()
{
	cout << "品牌:" <<  _brand << endl
		 << "价格:" << price_ << endl;
}

int main(void)
{
	test0();
	return 0;
}
