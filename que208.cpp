#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;
        sort(a.begin(),a.end());
        long long sum=0;
        for(int i=n-1;i>=0;i-=2){
            sum += a[i];
        }
        cout<<sum<<endl;
    }

    return 0;
}