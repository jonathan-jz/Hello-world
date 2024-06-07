#include<iostream>
#include<string.h>

using std::cout;
using std::endl;

class Computer{
    public:
        Computer(const char * brand,double price)
        :_brand(new char[strlen(brand)+1]())
        ,_price(price)
        {
            strcpy(_brand,brand);
            cout <<"Computer(const char*,double)"<<endl;
        }
    
    #if 0
        Computer(const Computer&rhs)
        :_brand(rhs._brand)
        ,_price(rhs._price)
        {}
    #endif

    Computer(const Computer&rhs)
    :_brand(new char[strlen(rhs._brand)+1]())
    ,_price(rhs._price)
    {
        strcpy(_brand,rhs._brand);
        cout <<"Computer(const Computer&)"<<endl;
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
        char *_brand;
        double _price;
};

void test0(){
    Computer c1("小米",7777);
    cout <<"sizeof(Computer):"<<sizeof(Computer)<<endl;
    cout <<"sizeof(c1):"<<sizeof(c1)<<endl;

    cout<<"C1:";
    c1.print();

    Computer c2(c1);
    cout <<"C2:";
    c2.print();
}


int main(void){
    test0();
    return 0;
}