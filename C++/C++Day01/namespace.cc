#include<iostream>
using namespace std;

namespace wd
{
    int number = 0;
    void dispaly(){
        cout << "This is wd space"<<endl;
        cout << "number is "<<number<<endl;
    }
} // namespace wd
 

 namespace zhang
 {

    int number = 1;
    void show(){
        cout <<"this is show space"<<endl;
        cout <<"This is zhang's number"<<number<<endl;
    }    
 } // namespace zhang
 

int main(int argc,char* argv[]){
    wd::dispaly();

    cout << wd::number<<endl;
    cout <<wd::dispaly<<endl;
    cout <<"++++++++++++++++++++++++++"<<endl;
    using zhang::show;
    cout<<zhang::number<<endl;
    show();

}