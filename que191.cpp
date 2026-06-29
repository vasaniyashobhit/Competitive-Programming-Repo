#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool comp(int a,int b){
    return a>b;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        sort(a.begin(),a.end(),comp);
        for(auto it:a) cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}