#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;
        int count = 0,neg=0;
        for(int i=0;i<n;i++){
            if(a[i]==0) count++;
            if(a[i]==-1) neg++;
        }
        if(neg%2!=0) count+=2;
        cout<<count<<endl;
    }

    return 0;
}