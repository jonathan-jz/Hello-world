#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ofstream;
 
void test0() 
{
	//ofstream当文件不存在时，直接创建文件, 之后进行写入
	//如果文件存在，会先清空文件中的内容，之后再进行写入
	std::string filename = "test.txt";
	ofstream ofs(filename);
	if(!ofs.good()) {
		cout << "ofstream open file error" << endl;
		return;
	}

	std::string line("this is a new line");
	ofs << line;

	ofs.close();
} 
 
void test1() 
{
	std::string filename = "test.txt";
	ofstream ofs(filename, std::ios::out|std::ios::app);
	if(!ofs.good()) {
		cout << "ofstream open file error" << endl;
		return;
	}

	//输出流定位函数的名字与输入流的最后一个字母不同
	int pos = ofs.tellp();
	cout << "pos:" << pos << endl;

	ofs.seekp(0);
	pos = ofs.tellp();
	cout << "pos:" << pos << endl;

	//app模式可以保证每一次写入文件的操作，
	//都是在文件的末尾添加数据
	std::string line("\nhello,wuhan");
	ofs << line;

	ofs.close();
} 
int main(void)
{
	test0(); 
	test1();
	return 0;
}
