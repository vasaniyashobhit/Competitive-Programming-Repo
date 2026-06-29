#include<bits/stdc++.h>
using namespace std;

// class A{
//     public:
//     virtual void msg(){
//         cout<<"hello student"<<endl;
//     }
// };

// class C: public A{
//     public:
//     void msg(){
//         cout<<"hello teacher"<<endl;
//     }
// };

// int main(){
//     A *ref = new C();
//     ref->msg();
// }

class A{    // abstract class // class which contain pure-virtual function or do nothing method
    public:
    virtual void fun() = 0;  // do nothing method // pure virtual function
    // C++ says dont call this method
    // for this c++ rule... you cant create object of this class

    virtual void func(){  // virtual function
        cout<<"hello";
    }

    void msg(){
        cout<<"hello student"<<endl;
    }
};

class C: public A{
    public:
    void fun(){
        cout<<"hello teacher"<<endl;
    }
};

int main(){
    A *p = new C();
    p->msg();
}