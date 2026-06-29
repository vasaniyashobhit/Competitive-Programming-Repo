#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int a,b,c,d; cin>>a>>b>>c>>d;
        bool ans = true;
        if(2*(1+min(a,b))<max(a,b)){
            ans = false;
        }
        c -= a;
        d -= b;
        if(2*(1+min(c,d))<max(c,d)){
            ans = false;
        }

        if(ans==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

    return 0;
}