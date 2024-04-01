#include<iostream>

namespace{
    //匿名空间
    int  ar = 11;
    void fun(){
    std::cout<<"hello world0"<<std::endl;
    }
}

namespace wd{
    int number = 3;
    void display(){
        std::cout <<number<<std::endl;
        std::cout <<"This is first"<<std::endl;
    }
}

namespace zhang{
    int num = 3;
    void display1(){
        std::cout <<"This is another one"<<std::endl;
        std::cout <<"Second"<<std::endl;
        std::cout <<num<<std::endl;
    }
}

using zhang::display1;


namespace sd{

    void print();
    void bl();
    void print(){
    std::cout << "Here is "<<std::endl;
    }
}

namespace sd{
    void bl(){
        std::cout <<"no way"<<std::endl;
    }
}
int main(){
    wd::display();
    std::cout <<"+++++++++++++++++++++++++++++++++="<<std::endl;
    display1();
    
    std::cout <<"+++++++++++++++++++++++++++++++++="<<std::endl;

    sd::print();
    sd::bl();

    std::cout <<"+++++++++++++++++++++++++++++++++="<<std::endl;
    ::fun();

    return 0;
}