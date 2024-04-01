#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;//动态数组
using std::string;


//动态扩容策略:
//
 
void test0() 
{
	//容器
	vector<int> numbers;
	//vector<string> strs;
	//当前数组中有多少个元素
	cout << numbers.size() << endl;
	//当前数组能够容纳多少个元素
	cout << numbers.capacity() << endl;

	numbers.push_back(1);
	cout << numbers.size() << endl;
	cout << numbers.capacity() << endl;
	numbers.push_back(1);
	cout << numbers.size() << endl;
	cout << numbers.capacity() << endl;
	numbers.push_back(1);
	cout << numbers.size() << endl;
	cout << numbers.capacity() << endl;
	numbers.push_back(1);
	cout << numbers.size() << endl;
	cout << numbers.capacity() << endl;
	numbers.push_back(1);
	cout << numbers.size() << endl;
	cout << numbers.capacity() << endl;
	numbers.push_back(1);
	cout << numbers.size() << endl;
	cout << numbers.capacity() << endl;
	numbers.push_back(1);
	cout << numbers.size() << endl;
	cout << numbers.capacity() << endl;
	numbers.push_back(1);
	cout << numbers.size() << endl;
	cout << numbers.capacity() << endl;
	numbers.push_back(1);
	cout << numbers.size() << endl;
	cout << numbers.capacity() << endl;
} 

void test1()
{
	//直接初始化1000个元素
	vector<int> numbers(1000, 1);
	cout << "size:" << numbers.size() << endl;
	cout << "capa:" << numbers.capacity() << endl;
	for(auto & elem : numbers) {
		cout << elem << " ";
	}
	cout << endl;

	vector<int> numbers2;
	//只开辟空间，并不存放元素
	numbers2.reserve(1000);
	cout << "size:" << numbers2.size() << endl;
	cout << "capa:" << numbers2.capacity() << endl;
	for(int idx = 0; idx < 10; ++idx) {
		numbers2.push_back(idx);
	}

	//遍历vector中的元素
	for(size_t idx = 0; idx < numbers2.size(); ++idx)
	{
		cout << numbers2[idx] << " ";
	}
	cout << endl;

	//增强for循环
	for(auto & elem : numbers2) {
		cout << elem << " ";
	}
	cout << endl;

}
 
int main(void)
{
	test0(); 
	test1();
	return 0;
}
