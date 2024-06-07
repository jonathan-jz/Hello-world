#include<iostream>
namespace c{
    int number = 3;
    void display(){
        std::cout<<"display()"<<std::endl;
    }
    void print1(){
        std::cout <<"print()"<<std::endl;
    }
}
namespace d{
    using c::print1;
    void print(){
        std::cout <<c::number<<std::endl;
        c::print1();
    }
}

int main(int argc,char* argv[]){
    using namespace d;
    d::print();
    return 0;
}