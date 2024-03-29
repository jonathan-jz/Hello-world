#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
	String()
	: _pstr(nullptr)
	{
		cout << "String()" << endl;
	}

	String(const char *pstr)
	: _pstr(new char[strlen(pstr) + 1]())
	{
		strcpy(_pstr, pstr);
		cout << "String(const char*)" << endl;
	}


	String(const String & rhs)
	: _pstr(new char[strlen(rhs._pstr) + 1]())
	{
		strcpy(_pstr, rhs._pstr);
		cout << "String(const String &)" << endl;
	}

	String & operator=(const String & rhs)
	{//si bu qu 
		if(this != & rhs) {
			if(_pstr) {
				delete [] _pstr;
			}
			_pstr = new char[strlen(rhs._pstr) + 1]();
			strcpy(_pstr, rhs._pstr);
		}
		return *this;
	}

	~String()
	{
		if(_pstr) {
			delete [] _pstr;
			_pstr = nullptr;
		}
		cout << "~String()" << endl;
	}

#if 0
	String(const String &rhs);
	String &operator=(const String &rhs);
    size_t length() const;
    const char * c_str() const;
#endif
	void print()
	{
		if(_pstr) {
			printf("_pstr:%p\n", _pstr);
			cout << _pstr << endl;
		}
#if 0
		int * p = nullptr;
		cout << p << endl;
		cout << "1112" << endl;
		//如果cha*指针是空指针，cout输出时，程序会崩溃
		cout << _pstr << endl;
		cout << "333" << endl;
#endif
	}

private:
	char * _pstr;
};
 
void test0() 
{
	String str1;
	str1.print();

	String str2 = "Hello,world";
	String str3("wangdao"); 

	str2.print();
	str3.print();

	String str4 = str3;
	str4.print();

	str4 = str2;
	str4.print();
} 
 
int main(void)
{
	test0();
	return 0;
}
