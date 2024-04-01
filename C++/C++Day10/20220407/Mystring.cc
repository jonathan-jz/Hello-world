 ///
 /// @file    Mystring.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-03-31 17:39:27
 ///

#include <string.h>

#include <iostream>
using std::cout;
using std::endl;


// _pstr -->  4个字节ref | 字符串的内容

class String
{
public:
	String()
	: _pstr(new char[1 + 4]() + 4)
	{
		//初始化引用计数
		initRefcount();
		cout << "String()" << endl;
	}

	String(const char *pstr)
	: _pstr(new char[strlen(pstr) + 1]() + 4)
	{
		cout << "String(const char*)" << endl;
		initRefcount();
		strcpy(_pstr, pstr);
	}


	String(const String & rhs)
	: _pstr(rhs._pstr)
	{
		cout << "String(const String &)" << endl;
		increaseRefcount();
	}

	String & operator=(const String & rhs)
	{//四部曲
		if(this != & rhs) {
			release();//先释放左操作数的空间

			_pstr = rhs._pstr;// 浅拷贝
			increaseRefcount();// 再将引用计数加1
		}
		return *this;
	}

	void release()
	{
		//先将引用计数减1， 
		//当引用计数为0时，才真正释放对象
		decreaseRefcount();
		if(getRefcount() == 0) {
			delete [] (_pstr - 4);
			_pstr = nullptr;
			cout << ">>> delete _pstr" << endl;
		}
	}

	~String() {
		release();
		cout << "~String()" << endl;
	}

	int getRefcount() const {	return *(int*)(_pstr - 4);	}

	friend std::ostream & operator<<(std::ostream &os, const String &);
private:
	//inline函数
	void initRefcount()
	{	*(int*)(_pstr - 4) = 1;	}

	void increaseRefcount() //引用计数加1
	{	++*(int*)(_pstr - 4);	}

	void decreaseRefcount() //引用计数减1
	{	--*(int*)(_pstr - 4);	}

private:
	//_pstr所指向的空间的首地址是字符串的第一个字符
	char * _pstr;
};
 
std::ostream & operator<<(std::ostream &os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}

void test0() 
{
	String str1;
	cout << "str1:" << str1 << endl;
	cout << "str1's ref:" << str1.getRefcount() << endl;

	String str2 = str1;
	cout << "str2:" << str2 << endl;
	cout << "str2's ref:" << str2.getRefcount() << endl;


	String str3 = "Hello,world";
	cout << "str3: " << str3 << endl;
	String str4 = str3; 
	cout << "str4: " << str4 << endl;
	cout << "str3's ref:" << str3.getRefcount() << endl;
	cout << "str4's ref:" << str4.getRefcount() << endl;
	cout << endl;

	String str5("wangdao");
	cout << "str5:" << str5 << endl;
	cout << "str5's ref:" << str5.getRefcount() << endl;

	String str6 = str5;

	str5 = str4;//
	cout << "执行赋值操作之后:" << endl;
	cout << "str5:" << str5 << endl;
	cout << "str3's ref:" << str3.getRefcount() << endl;
	cout << "str4's ref:" << str4.getRefcount() << endl;
	cout << "str5's ref:" << str5.getRefcount() << endl;
#if 0

	str2.print();
	str3.print();

	String str4 = str3;
	str4.print();

	str4 = str2;
	str4.print();
#endif
} 
 
int main(void)
{
	test0();
	return 0;
}
