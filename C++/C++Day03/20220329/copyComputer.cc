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
	
	//系统提供的拷贝构造函数
#if 0
	Computer(const Computer &rhs)
	: _brand(rhs._brand) // 浅拷贝, 只拷贝地址值
	, _price(rhs._price)
	{}
#endif
	Computer(const Computer &rhs)
	: _brand(new char[strlen(rhs._brand) + 1]())//先开空间  
	, _price(rhs._price)
	{
		strcpy(_brand, rhs._brand);//再复制数据 => 深拷贝
		cout << "Computer(const Computer&)" << endl;
	}


	void print()
	{
		cout << "品牌:" <<  _brand << endl
			 << "价格:" << _price << endl;
	}

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

	cout << "c1:";
	c1.print();

	Computer c2(c1);//调用Computer的拷贝构造函数
	cout << "c2:";
	c2.print();


} 
 
int main(void)
{
	test0();
	return 0;
}
