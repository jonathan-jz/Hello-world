#include<iostream>
using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix = 0,int iy = 0)
    :_ix(ix)
    ,_iy(iy){
        cout <<"Point(int ,int)"<<endl;
    }

    void print(){
        cout <<"("<<_ix
            <<","<<_iy
            <<")"<<endl;
    }
    ~Point(){
        cout <<"~Point()"<<endl;
    }

private:
    int _ix;
    int _iy;
};

void test0(){
    Point pt;
    cout <<"Pt:";
    pt.print();

    Point pt2(1,2);
    cout <<"Pt2:";
    pt2.print();
}

int main(){

    test0();
    return 0;
}