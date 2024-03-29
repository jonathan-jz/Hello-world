#include <iostream>
using std::cout;
using std::endl;

class Stack
{
public:
	Stack(int capacity)
	: _top(-1)
	, _capacity(capacity)
	, _data(new int[capacity]()) 
	{
	}

	~Stack()
	{	
		if(_data) {
			delete [] _data;
			_data = nullptr;
		}
	}

	bool empty() const
	{
		return  _top == -1;
	}

	bool full() const
	{
		return _top + 1 == _capacity;
	}

	int top() const {	return _data[_top];	}

	void push(int number) 
	{
		if(!full()) {
			_data[++_top] = number;
		} else {
			cout << "stack is full, cannot push any data!" << endl;
		}
	}

	void pop() 
	{
		if(!empty()) {
			--_top;
		} else {
			cout << "stack is empty, no more data!" << endl;
		}
	}

private:
	int _top;
	int _capacity;
	int * _data;
};
 
void test0() 
{
	Stack stack(10);
	cout << "stack是否为空?" << stack.empty() << endl;
	stack.push(1);
	cout << "stack是否为空?" << stack.empty() << endl;

	for(int idx = 2; idx < 12; ++idx) {
		stack.push(idx);
	}
	cout << "stack是否已满?" << stack.full() << endl;

	while(!stack.empty()) {
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;
	cout << "stack是否为空?" << stack.empty() << endl;

} 
 
int main(void)
{
	test0();
	return 0;
}
