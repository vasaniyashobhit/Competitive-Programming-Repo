#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long x,y,k; cin>>x>>y>>k;
        long long stick = (k*y) + k -1;
        long long n = stick/(x-1);
        if(stick%(x-1)!=0) n++;
        cout<<(k+n)<<endl;
    }

    return 0;
}