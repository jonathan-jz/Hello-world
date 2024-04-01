 ///
 /// @file    arrowOperator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-04-05 17:23:25
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Data
{
public:
	Data(int data = 0): _data(data){
		cout << "Data(int=0)" << endl;
	}

	int getData() const {	return _data;	}

	~Data() {	cout << "~Data()" << endl;	}
private:
	int _data;
};

class MiddleLayer
{
public:
	MiddleLayer(Data * pdata)
	: _pdata(pdata)
	{
		cout << "MiddleLayer()" << endl;
	}

	//箭头访问运算符
	Data * operator->()
	{	return _pdata;	}

	//解引用运算符
	Data & operator*()
	{	return *_pdata;	}

	~MiddleLayer()
	{
		if(_pdata) {
			delete _pdata;
		}
		cout << "~MiddleLayer()" << endl;
	}

private:
	Data * _pdata;//保存的是堆空间的数据

};

class ThirdLayer
{
public:
	ThirdLayer(MiddleLayer * p)
	: _pml(p)
	{	cout << "ThirdLayer(MiddleLayer*)" << endl;	}

	MiddleLayer & operator->()
	{	return *_pml;	}

	~ThirdLayer()
	{
		if(_pml) {
			delete _pml;
		}
		cout << "~ThirdLayer()" << endl;
	}

private:
	MiddleLayer * _pml;//堆空间的对象
};

void test1()
{
	//可以不掌握
	ThirdLayer tl(new MiddleLayer(new Data(11)));
	tl->getData();//简化实现, 第三层的对象可以直接调用Data类的相关函数

	((tl.operator->()).operator->())->getData();
}

 
void test0() 
{
	//MiddleLayer就是一个智能指针的雏形
	MiddleLayer p(new Data(10));
	cout << p->getData() << endl;//把对象当成指针去调用函数
	//上面等价与下面这一句，相当于简化了
	(p.operator->())->getData();
	cout << (*p).getData() << endl;
	(p.operator*()).getData();
} 


 
int main(void)
{
	test0();
	return 0;
}
