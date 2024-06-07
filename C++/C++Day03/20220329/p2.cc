#include<iostream>
using std::cout;
using std::endl;

class Point{
public:

#if 0
    Point(){
        cout <<"Point()"<<endl;
        _ix = 0;
        _iy = 0;
    }


#endif



    Point(int ix = 0,int iy = 0){
        cout <<"Point(int ,int )"<<endl;
        _ix = ix;
        _iy = iy;
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


void test(){
    Point pt;
    cout <<"pt:";
    pt.print();


    Point pt2(1,3);
    cout <<"Pt2:";
    pt2.print();

}


int main(){

    test();
    return 0;
}