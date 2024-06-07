#include<iostream>
namespace c{
    int number = 3;
    void display(){
        std::cout<<"display()"<<std::endl;
    }
    void print(){
        std::cout <<"print()"<<std::endl;
    }
}
using c::display;
int main(int argc,char* argv[]){
    display();
    return 0;
}