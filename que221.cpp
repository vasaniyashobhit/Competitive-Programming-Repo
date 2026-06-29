#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,m; cin>>n>>m;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;
        sort(a.begin(),a.end());

        long long count=0;
        for(long long i=n-1;i>=0;i--){
            count += m*(a[i]);
            m--;
            if(m==0) break;
        }
        cout<<count<<endl;
    }
    return 0;
}