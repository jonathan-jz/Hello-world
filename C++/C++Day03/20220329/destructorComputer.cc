#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer(const char * brand, double price)
	: _brand(new char[strlen(brand) + 1]())
	, _price(price)
	{
		strcpy(_brand, brand);
		cout << "Computer(const char*, double)" << endl;
	}

	void print()
	{
		cout << "品牌:" <<  _brand << endl
			 << "价格:" << _price << endl;
	}

	//如果不显式定义析构函数，系统也会自动提供
	//一个析构函数；
	//当系统提供的析构函数不再满足需求时，
	//必须要显式定义
	//
	//析构函数什么情况下会自动调用?
	//答：局部对象/全局对象/静态对象,对象被销毁时会自动调用
	//	  对于堆对象，只有执行delete表达式之后会自动调用
	~Computer()
	{
		release();
	}

	void release()
	{
		if(_brand) {
			delete [] _brand;
			_brand = nullptr;//NULL
		}
		cout << "~Computer()" << endl;
	}

private:
	char * _brand;//由于_brand申请了堆空间的资源
	double _price;//必须要进行回收,系统提供
};

//Computer c2("Huawei mate14", 8888);
//static Computer c3("拯救者Y", 9999);
 
void test0() 
{
	Computer c1("小米", 7777);//创建对象
	cout << "sizeof(Computer):" << sizeof(Computer) << endl;
	cout << "sizeof(c1): " << sizeof(c1) << endl;

	c1.print();
	c1.release();//可以显式调用析构函数
				   //对于析构函数不建议主动调用，都是
				   //被动自动调用



//	Computer * pc = new Computer("Thinkpad x1", 11111);
//	delete pc;
} 
 
int main(void)
{
	test0();
	return 0;
}
