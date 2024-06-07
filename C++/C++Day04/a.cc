#include<iostream>
using namespace std;

class Foo{
public:
    Foo(int x)
    :_iy(x),_ix(_iy){
        cout <<"Foo(int)"<<endl;
    }
    void print(){
        cout <<"("<<_ix
            <<","<<_iy
            <<")"<<endl;
    }   
private:
    int _iy;
    int _ix;
};

void test0(){
    Foo f(10);
    f.print();
}


int main(){
    test0();
    return 0;
}