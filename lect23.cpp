#include<bits/stdc++.h>
using namespace std;

class Boss{
    public:
    virtual void fun() = 0;
    void salary(){
        cout<<"you take salary"<<endl;
    }
};

class Employee:public Boss{
    public:
    void fun(){
        cout<<"taks complete"<<endl;
    }
};

int main(){
    Employee e1;
    e1.fun();
    e1.salary();

    return 0;
}