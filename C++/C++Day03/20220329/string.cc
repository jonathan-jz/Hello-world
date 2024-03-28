#include <string.h>

#include <iostream>
using std::cout;
using std::endl;
 
void test0() 
{
	//字符数组
	char str1[] = "hello,world";//还包含一个空字符'\0'
	//数组名是一个常量，不能进行修改
	//str1 = 0x1000;//error

	//常量指针 ==> C风格的字符串类型，一般就认为是const char *
	const char * pstr2 = "hello,wuhan";
 
	printf("str1: %s\n", str1);
	int len1 = strlen(str1);//11  获取字符串长度的方式
	int len2 = sizeof(str1);//12
	printf("len1:%d, len2: %d\n", len1, len2);
	int len3 = strlen(pstr2);//11
	int len4 = sizeof(pstr2);// 8  64位系统中一个指针占据8个字节
	printf("len3:%d, len4: %d\n", len3, len4);

	//字符串拼接
	//char * pstr3 = (char *)malloc(len1 + len2);
	char * pstr3 = (char *)calloc(1, len1 + len2);
	strcpy(pstr3, str1);
	strcat(pstr3, pstr2);
	printf("pstr3:%s\n", pstr3);

	for(int i = 0; i < len2; ++i) {
		printf("%c\n", pstr2[i]);
	}
} 

void test1()
{
	cout << "\n\ntest1:\n";
	//C++风格的字符串
	//
	//将C风格字符串转换为C++风格的写法
	std::string s1 = "helllo,world";
	cout << s1.size() << endl;
	cout << s1.length() << endl;

	std::string s2 = "hello,wuhan";

	//字符串拼接, 使用起来更方便
	std::string s3 = s1 + s2;
	cout << "s3:" << s3 << endl;

	
	//字符串的遍历
	for(size_t idx = 0; idx < s3.size(); ++idx) {
		cout << s3[idx] << " ";
	}
	cout << endl;

	s3.append("123");
	cout << "s3:" << s3 << endl;
	
	//C++风格的字符串转换为C风格的字符串
	const char * pstr = s3.c_str();
	cout << "pstr:" << pstr << endl;

	//截取子串
	std::string s4 = s3.substr(7, 5);
	cout << "s4:" << s4 << endl;

}
 
int main(void)
{
	test0(); 
	test1();
	return 0;
}
