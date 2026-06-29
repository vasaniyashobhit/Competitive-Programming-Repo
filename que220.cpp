#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long a,b; cin>>a>>b;
        long long lcmm = (a*b)/__gcd(a,b);
        if(a==b){
            cout<<0<<endl;
        }
        else if(a==lcmm || b==lcmm){
            cout<<1<<endl;
        }
        else{
            cout<<2<<endl;
        }
        // int count = 0;
        // count += lcmm/a;
        // count += lcmm/b;
    }
    return 0;
}