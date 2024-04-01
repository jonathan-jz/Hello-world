#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::istringstream;
using std::ostringstream;
 
void test0() 
{
	int number = 1024;
	double number2 = 11.11;

	//类比sprintf();
	ostringstream oss;
	oss << number << " -->" << number2;
	string s = oss.str();
	cout << "s:" << s << endl;
} 

void test1()
{
	string line("1024 11.11");
	istringstream iss(line);
	int number;
	double number2;
	iss >> number >> number2;
	cout << "number:" << number << endl
		 << "number2:" << number2 << endl;
}

struct Record
{
	string key;
	string value;
};

void readConfiguration()
{
	std::ifstream ifs("server.conf");
	if(!ifs.good()) {
		cout << "ifstream open error" << endl;
		return;
	}
	vector<Record> configs;

	string line;
	string key, value;
	while(getline(ifs, line)) {
		istringstream iss(line);
		iss >> key >> value;
		Record record;
		record.key = key;
		record.value = value;
		configs.push_back(record);
		cout << key << " --> " << value << endl;
	}
	
	ifs.close();
}
 
int main(void)
{
	 test0();
	 cout<<"+++++++"<<endl;
	 test1(); 
	 cout <<"++++++++++++++"<<endl;
	readConfiguration();
	return 0;
}
