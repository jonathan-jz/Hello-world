#include<iostream>
// using namespace std;
namespace b{
    int number = 1;
    void display(){
        std::cout <<number<< std::endl;
    }
}

int main(int argc,char* argv[]){
    b::display();
    return 0;
}