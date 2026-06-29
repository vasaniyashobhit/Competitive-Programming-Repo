#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long> &a, vector<long long> &pref, long long op, long long k){
    long long n = a.size();
    if(pref[n-1]<=k) return true;
    long long ans = __LONG_LONG_MAX__;
    for(long long op2=0; op2<=min(n-1,op);op2++){
        long long op1 = op-op2;
        long long firstelement = a[0]-op1;
        long long sum = pref[n-op2-1];
        sum += (op1>0) ? firstelement-pref[0] : 0;
        sum += op2*(firstelement);
        ans = min(ans,sum);
    }
    if(ans<=k) return true;
    return false;
}

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
        
        long long s=0,e=1e15;
        long long ans = -1;
        while(s<=e){
            long long mid = s + (e-s)/2;
            if(check(a,pref,mid,k)){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        cout<<ans<<endl;
    }

    return 0;
}