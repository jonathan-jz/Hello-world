#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Student
{
public:
	Student(int id, const char * name)
	: _id(id)
	, _name(new char[strlen(name) + 1]())
	{
		cout << "Student()" << endl;
		strcpy(_name, name);
	}

	void print() const
	{
		cout << "id:" << _id << endl
			 << "name:" << _name << endl;
	}

	~Student()
	{
		if(_name) {
			delete [] _name;
			_name = nullptr;
			cout << "~Student()" << endl;
		}
	}

private:
	//空间的申请
	void * operator new(size_t sz);

	//回收对象本身所在的空间
	void operator delete(void * pret);

private:
	int _id;
	char * _name;
};

 
void test0() 
{
	cout << "sizeof(Student):" << sizeof(Student) << endl;
	//不能生成堆对象
	//Student * ps1 = new Student(100, "Jackie");//error
	//ps1->print();

	//delete ps1;

	//栈对象
	Student s2(101, "Rose");//ok
	s2.print();
} 
 
int main(void)
{
	test0();
	return 0;
}
