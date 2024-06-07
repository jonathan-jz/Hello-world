#include<iostream>
#include<string.h>
using std::cout;
using std::endl;

class Computer{
public:
    void setBrand(const char* brand){
        strcpy(_brand,brand);
    }
    void setPrice(double price){
        _price = price;
    }
    void print(){
        cout <<"品牌："<< _brand<<endl
        <<"价格："<<_price<<endl;
    }
    
private:
    char _brand[20];
    double _price;
    double m_price;
};

void test0(){
    Computer c1;
    c1.setBrand("小米");
    c1.setPrice(9999);
    c1.print();
}

int main(void){
    test0();
    return 0;
}