#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,k; cin>>n>>k;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;
        sort(a.begin(),a.end());
        
        vector<long long> pref(n);
        pref[0] = a[0];
        for(int i=1;i<n;i++) pref[i] = a[i]+pref[i-1];
        long long sum=0,maxsum=0;
        for(int i=0;i<=k;i++){
            sum = pref[n-i-1];
            sum -= (i!=k) ? pref[2*(k-i) - 1] : 0;
            maxsum = max(sum,maxsum);
        }
        cout<<maxsum<<endl;
    }

    return 0;
}