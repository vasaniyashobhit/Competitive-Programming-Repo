#include<iostream>
#include<string>
using namespace std;

int main(){

        int n,a,b,c,d; cin>>n>>a>>b>>c>>d;
        if(abs(b-c)<=1){
            if(a!=0 && d!=0){
                if(b>0 || c>0){
                    cout<<"Yes"<<endl;
                }
                else{
                    cout<<"No"<<endl;
                }
            }
            else{
                cout<<"Yes"<<endl;
            }

        }
        else{
            cout<<"No"<<endl;
        }
        
        
    return 0;
}