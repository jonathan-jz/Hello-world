#include<iostream>
#include<string.h>

using std::cout;
using std::endl;

struct Computer{
    void setBrand(const char * brand){
        strcpy(_brand,brand);
    }

    void setPrice(double price){
        _price = price;
    }
//
//    void price(){
//        cout <<"品牌："<<_brand<<endl
//            <<"价格：" <<_price<<endl;
//    }
    void print(){
        cout <<"品牌："<<_brand<<endl
            <<"价格："<<_price<<endl;
    }

    char _brand[20];
    double _price;
};
void test0(){
    Computer c1;
    c1.setBrand("xiaomi");
    c1.setPrice(7777);
    c1.print();
}


int main(){

    test0();
    return 0;
}