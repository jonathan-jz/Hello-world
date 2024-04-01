 ///
 /// @file    CharArray.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-04-05 17:08:00
 ///

#include <string.h>

#include <vector>
#include <iostream>
using std::cout;
using std::endl;

class CharArray
{
public:
	CharArray(const char * pdata)
	: _capacity(strlen(pdata) + 1)
	, _pdata(new char[_capacity]())
	{
		strcpy(_pdata, pdata);
	}

	int size() const {	return _capacity - 1;}

	char & operator[](int idx)
	{
		cout << "\nchar & operator[](int)" << endl;
		if(idx >= 0 && idx < size()) {
			return _pdata[idx];
		}else {
			static char nullchar = '\0';
			return nullchar;
		}
	}
	
	~CharArray()
	{
		if(_pdata) {
			delete [] _pdata;
		}
	}

private:
	size_t _capacity;
	char * _pdata;
};
 
void test0() 
{
	//vector内部也重载了下标访问运算符
	std::vector<int> numbers(10, 1);
	for(size_t idx = 0; idx < numbers.size(); ++idx) 
	{
		cout << numbers[idx] << " ";
	}
	cout << endl;

	//C++风格字符串内部也重载了下标访问运算符
	std::string s1("hello,world");
	for(size_t idx = 0; idx < s1.size(); ++idx) 
	{
		cout << s1[idx] << " ";
	}
	cout << endl;

	CharArray ca("hello,wuhan");
	for(int idx = 0; idx < ca.size(); ++idx) {
		cout << ca[idx];
	}
	cout << endl;
} 
 
int main(void)
{
	test0();
	return 0;
}
