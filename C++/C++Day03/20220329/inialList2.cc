#include <iostream>
using std::cout;
using std::endl;

class Foo
{
public:
	Foo(int x)
	: _iy(x)
	, _ix(_iy)
	{
		cout << "Foo(int)" << endl;
	}

	void print() {
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

private:
	int _iy;
	int _ix;
};
 
void test0() 
{
	Foo foo(10);
	cout << "foo:";
	foo.print();
} 
 
int main(void)
{
	test0();
	return 0;
}
