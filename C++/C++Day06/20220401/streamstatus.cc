#include <iostream>
#include <limits>
using std::cout;// std::ostream
using std::cin;//  std::istream
using std::endl;
using std::istream;

void printStreamStatus(istream & is)
{
	cout << "is.good():" << is.good() << endl;
	cout << "is.bad():" << is.bad() << endl;
	cout << "is.eof():" << is.eof() << endl;
	cout << "is.fail():" << is.fail() << endl;
}
 
void test0() 
{
	int number = -1;

	printStreamStatus(cin);
	cin >> number;// 输入流运算符
	cout << number << endl; // 输出流运算符
	printStreamStatus(cin);
	cin.clear();//重置流的状态
	cout << "\n重置流的状态:" << endl;
	printStreamStatus(cin);

	//流的内部是有缓冲区
	//清空缓冲区
	cin.ignore(1024, '\n');

	std::string s1;
	cin >> s1;
	cout << "s1:" << s1 << endl;
} 

void test1()
{//通过终端获取1个整型数据
	int number = -1;	
	while(cin >> number, !cin.eof())
	{
		if(cin.bad()) {
			cout << "cin has broken!" << endl;	
			return;
		} else if(cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "pls input a valid integer:\n";
		} else {
			cout << "number:" << number << endl;	
		}
	}
}
 
int main(void)
{
	test0(); 
	test1();
	return 0;
}
