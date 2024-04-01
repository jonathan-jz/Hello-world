#include <fstream>
#include <iostream>
#include <string>   //C++风格的字符串的头文件
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
 
void test0() 
{
	//当打开的文件不存在时，流的创建是失败的
	//文件输入流要求，打开的文件必须存在
	ifstream ifs("cout.cc");
	if(!ifs.good()) {
		cout << "ifstream open file eror!" << endl;
		return ;
	}
	
	string word;
	//输入流运算符以空格(\t)作为分隔符
	while(ifs >> word) {
		cout << word << endl;
	}

	ifs.close();//关闭文件流
} 

void test1() 
{
	//当打开的文件不存在时，流的创建是失败的
	//文件输入流要求，打开的文件必须存在
	ifstream ifs("cout.cc");
	//if(!ifs.good()) {
	if(!ifs) {
		cout << "ifstream open file eror!" << endl;
		return ;
	}
	
	//每一次读取一行数据
	//getline
	//方式一：使用成员函数getline来完成
	char buff[1000] = {0};
	while(ifs.getline(buff, 1000)) {
		cout << buff << endl;
	}

	ifs.close();//关闭文件流
} 

void test2() 
{
	//当打开的文件不存在时，流的创建是失败的
	//文件输入流要求，打开的文件必须存在
	ifstream ifs("cout.cc");
	//if(!ifs.good()) {
	if(!ifs) {
		cout << "ifstream open file eror!" << endl;
		return ;
	}
	
	//每一次读取一行数据
	//getline
	//方式二：使用函数getline来完成, 更通用的写法
	//std::getline的函数声明
	// ifstream & getline(ifstream &, string&);

	std::vector<string> file;
	file.reserve(100);
	string line;
	while(std::getline(ifs, line)) {
		//cout << line << endl;
		file.push_back(line);
	}
	
	//vector
	for(auto & line : file) {
		cout << line << endl;
	}

	cout << "file.size: " << file.size()  << endl;
	cout << "file.capacity:" << file.capacity() << endl;
	file.shrink_to_fit();//释放多余的空间
	cout << "file.size: " << file.size()  << endl;
	cout << "file.capacity:" << file.capacity() << endl;


	ifs.close();//关闭文件流
} 

void test3()
{
	//打开文件的方式
	ifstream ifs;
	ifs.open("cout.cc");
	if(!ifs) {
		cout << "ifstream open file eror!" << endl;
		return ;
	}

	//获取一个文件的长度
	int pos = ifs.tellg();
	cout << "pos:" << pos << endl;

	//偏移文件指针到文件的末尾
	//std::ios::cur
	//std::ios::beg
	//std::ios::end
	ifs.seekg(0, std::ios::end);
	pos = ifs.tellg();
	cout << "pos:" << pos << endl;
	ifs.seekg(0);//回到文件的开头位置
	
	char * pdata = new char[pos]();
	ifs.read(pdata, pos);//读取指定字节的数据

	string file(pdata, pos);
	cout << file;

	ifs.close();
}

void test4()
{
	ifstream ifs;
	ifs.open("cout.cc", std::ios::in|std::ios::ate);
	if(!ifs) {
		cout << "ifstream open file eror!" << endl;
		return ;
	}
	
	int pos = ifs.tellg();
	cout << "pos:" << pos << endl;
}
 
int main(void)
{
	test0();
	cout <<"+++++++++++++++++"<<endl;
	test1(); 
	cout<<"++++++++++++++++++"<<endl;
	test2();
	cout <<"++++++++++++++++++++"<<endl;
	test3(); 
	cout <<"++++++++++++++++++++++"<<endl;
	test4(); 
	return 0;
}
