#include <iostream>
using std::cout;
using std::endl;

class Queue
{
public:
	Queue(int capacity)
	: _front(0)
	, _rear(0)
	, _capacity(capacity)
	, _data(new int[_capacity]())
	{}

	~Queue() {
		if(_data) {
			delete [] _data;
			_data = nullptr;
		}
	}

	bool empty() const
	{	return _front == _rear;	}

	bool full() const 
	{	return _front == (_rear + 1) % _capacity;}

	void push(int num)
	{
		if(!full()) {
			_data[_rear++] = num;
			_rear %= _capacity;
		} else {
			cout << "queue is full, cannot push any more data!" << endl;
		}
	}

	void pop()
	{
		if(!empty()) {
			++_front;
			_front %= _capacity;
		} else {
			cout << "queue is empty, no more data!" << endl;
		}
	}

	int front() const {	return _data[_front];	}

	//注意
	int back() const {	return _data[(_rear - 1 + _capacity) % _capacity];}


private:
	int _front;
	int _rear;
	int _capacity;
	int * _data;
};
 
void test0() 
{
	Queue que(10);
	cout << "que是否为空?" << que.empty() << endl;
	que.push(1);
	cout << "que是否为空?" << que.empty() << endl;

	for(int idx = 2; idx < 12; ++idx) {
		que.push(idx);
	}
	cout << "que是否已满?" << que.full() << endl;

	//队列头部元素出队
	que.pop();
	//队尾元素入队
	que.push(10);

	cout << "此时que尾部的元素是:" << que.back() << endl;

	while(!que.empty()) {
		cout << que.front() << " ";
		que.pop();
	}
	cout << endl;
	cout << "que是否为空?" << que.empty() << endl;
 
} 
 
int main(void)
{
	test0();
	return 0;
}
