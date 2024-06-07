#include<iostream>
using std::cout;
using std::endl;

class Point{
public:
    Point(){
        cout <<"Point()"<<endl;
        _ix = 0;
        _iy = 0;
    }
    Point(int ix,int iy){
        cout <<"Point(int,int)"<<endl;
        _ix = ix;
        _iy = iy;
    }

    void Print(){
        cout <<"("<<_ix
            <<","<<_iy
            <<")"<<endl;
    }

private:
    int _ix;
    int _iy;
};


void test0(){
    Point pt;
    cout <<"Pt:";
    pt.Print();

    Point pt2(1,2);
    cout <<"Pt2:";
    pt2.Print();
}

int main(){
    test0();

    return 0;
}