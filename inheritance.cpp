#include <iostream>

using namespace std;

class name{
    public:
   
    void show(){
        cout <<"Hello i am a parent class:"<<endl;
    }
};

class age:public name{
    public:
    
    void display(){
        cout<<"Hello i am a child class:"<<endl;
    }

};
class statement:public age{
    public:
    void STAT(){
        cout <<"Hello i am a superchild class:"<<endl;
    }
};

int main(){
    statement a;
    a.show();
    a.display();
    a.STAT();
    return 0;
}