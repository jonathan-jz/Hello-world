#include<iostream>
using std::endl;
using std::cout;

class Point{
    public:
        Point(int ix = 0,int iy = 0)
        :_ix(ix),_iy(iy){
            cout <<"Point(int,int)"<<endl;
        }

        Point(const Point &rhs)
        :_ix(rhs._ix),_iy(rhs._iy){
            cout <<"Point(const Point&)"<<endl;
        }
        void print(){
            cout <<"("<<_ix
                <<","<<_iy
                <<")"<<endl;
        }

    private:
        int _ix;
        int _iy;
};


void test0(){
    int a = 1;
    int b = a;
    Point pt;
    cout <<"pt:";
    pt.print();

    Point pt2 = pt;
    cout <<"Pt2:";
    pt2.print();

    Point pt3(pt);
    cout<<"pt3:";
    pt3.print();
}


int main(){
    test0();
    return 0;
}