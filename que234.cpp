#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long>a(n);
        for(long long &it:a) cin>>it;
        sort(a.begin(),a.end());

        long long lar = 0;
        for(long long i=0;i<n;i+=2){
            long long diff = abs(a[i+1]-a[i]);
            lar = max(lar,diff);
        }
        cout<<lar<<endl;
    }

    return 0;
}