#include <iostream>
using std::cout;
using std::endl;


class Singleton
{
public:
	//静态成员函数不需要通过对象调用
	//可以直接通过类名调用
	static Singleton * getInstance()
	{
		if(nullptr == _pInstance) {
			_pInstance = new Singleton();
		}
		return _pInstance;
	}

	static void destroy()
	{
		if(_pInstance) {
			delete _pInstance;
			_pInstance = nullptr;
		}
	}

	//...添加新的与业务有关的成员函数
	void print() const 
	{	cout << "Singleton::_data:" << _data << endl;}


private:
	//构造函数不能在类之外直接调用
	//但可以在类内部直接调用
	Singleton()
	: _data(100)
	{}

	~Singleton() { cout << "~Singleton()" << endl;}

private:
	//与业务相关的数据
	int _data;
	static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = nullptr;

//不能是全局静态对象
//Singleton s3;//error
//Singleton s4;//error
//static Singleton s5;//error
//static Singleton s6;//error

 
void test0() 
{
	//不能是栈对象
	//Singleton s1;//error  该语句不能编译通过
	//Singleton s2;//如果能够通过，就可以创建无数个对象
	//堆空间的对象
	//Singleton * ps1 = new Singleton();
	//
	Singleton * ps1 = Singleton::getInstance();
	Singleton * ps2 = Singleton::getInstance();
	cout << "ps1:" << ps1 << endl;
	cout << "ps2:" << ps2 << endl;

	//更常规的使用方式
	Singleton::getInstance()->print();

	//delete ps1;//直接使用delete表达式回收单例对象
	//在形式上来说，与对象的创建并不优雅
	//不希望该操作正常进行
	//delete ps2;
	Singleton::destroy();
} 
 
int main(void)
{
	test0();
	return 0;
}
