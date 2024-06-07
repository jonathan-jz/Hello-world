#include<iostream>
#include<string.h>
using std::cout;
using std::endl;

class Computer{
public:
    Computer(const char*brand,double price)
    :_brand(new char[strlen(brand)+1]())
    ,_price(price){
        strcpy(_brand,brand);
        cout <<"Computer(const char*,double)"<<endl;
    }
    void print(){
        cout <<"品牌："<<_brand<<endl
            <<"价格："<<_price<<endl;
    }
    ~Computer(){
        release();
    }
    void release(){
        if(_brand){
            delete[]_brand;
            _brand = nullptr;
        }
        cout <<"~Computer()"<<endl;
    }

private:
    char* _brand;
    double _price;
};

void test0(){
    Computer c1("小米",7777);
    cout<<"sizeof(computer):"<<sizeof(Computer)<<endl;
    cout <<"sizeof(c1):"<<sizeof(c1)<<endl;

    c1.print();
    c1.release();
}

int main(){

    test0();
    return 0;
}