#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;
        long long x; cin>>x;

        bool k1=false; // smaller 
        bool k2=false; // larger
        bool k3=false; // x is present
        for(int i=0;i<n;i++){
            if(a[i]<x) k1 = true;
            if(a[i]>x) k2 = true;
            if(a[i]==x) k3 = true;
        }

        if(k1==true && k2==true){
            cout<<"YES"<<endl;
        }
        else if(k3==true){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }

    return 0;
}