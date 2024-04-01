#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;
 
void test0() 
{
	//打开的文件是必须要存在。
	//不存在，就报错
	fstream fs("test1.txt");
	if(!fs.good()) {
		cout << "fstream open file error" << endl;
		return ;
	}
} 

void test1() 
{
	//打开的文件是必须要存在。
	//不存在，就报错
	fstream fs("test.txt");
	if(!fs.good()) {
		cout << "1fstream open file error" << endl;
		return ;
	}

	string line;
	getline(fs, line);
	cout << "line:" << line << endl;

	fs.close();
} 

void test2()
{
	fstream fs("1.txt");
	if(!fs.good()) {
		cout << "fstream open file error" << endl;
		return ;
	}

	int number = 0;
	for(int idx = 0; idx < 5; ++idx) {
		cin >> number;
		fs << number << " ";//输出流功能
	}

	int pos = fs.tellg();
	cout << "pos1:" << pos << endl;

	pos = fs.tellp();
	cout << "pos2:" << pos << endl;

	fs.seekg(0);//偏移到文件的开始位置
	for(int idx = 0; idx < 5; ++idx) {
		fs >> number;//输入流功能
		cout << "number:" << number << endl;
	}

	fs.close();
}
 
int main(void)
{
	// test0(); 
	/* test1(); */
	test2();
	return 0;
}
