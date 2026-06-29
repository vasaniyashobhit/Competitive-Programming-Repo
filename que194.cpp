#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n%2==0){
            for(int i=1;i<n;i++){
                if(i%2==0) cout<<3<<" ";
                else cout<<-1<<" ";
            }
            cout<<2<<endl;
        }
        else{
            for(int i=1;i<=n;i++){
                if(i%2==0) cout<<3<<" ";
                else cout<<-1<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}