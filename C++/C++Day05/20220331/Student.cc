#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

//放到Student类之外，针对于所有类型的
	void * operator new(size_t sz)
	{
		cout << "void * operator new(size_t)" << endl;
		void * pret = malloc(sz);
		return pret;
	}

	//回收对象本身所在的空间
	void operator delete(void * pret)
	{
		cout << "void operator delete(void*)" << endl;
		free(pret);
	}

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

public:
	//放在类内部进行重载，只针对于Student类型的对象
#if 0
	//空间的申请
	void * operator new(size_t sz)
	{
		cout << "void * operator new(size_t)" << endl;
		void * pret = malloc(sz);
		return pret;
	}

	//回收对象本身所在的空间
	void operator delete(void * pret)
	{
		cout << "void operator delete(void*)" << endl;
		free(pret);
	}
#endif

private:
	int _id;
	char * _name;
};

 
void test0() 
{
	cout << "sizeof(Student):" << sizeof(Student) << endl;
	//堆对象
	Student * ps1 = new Student(100, "Jackie");
	ps1->print();

	delete ps1;

	//栈对象
	//Student s2(101, "Rose");
	//s2.print();
} 

void test1()
{
	int * pint = new int(1);
	cout << *pint << endl;
}
 
int main(void)
{
	/* test0(); */
	test1();
	return 0;
}
