#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,x; cin>>n>>x;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;
        
        sort(a.begin(),a.end());
        vector<long long> pref(n);
        pref[0] = a[0];
        for(long long i=1;i<n;i++) pref[i] = a[i]+pref[i-1];

        long long l=1,r=1e10;
        long long ans = 1;
        while(l<=r){
            long long mid = l + (r-l)/2;
            auto it = lower_bound(a.begin(),a.end(),mid);
            long long ind = it-a.begin();
            ind = max(ind,1ll);
            long long req = (mid*(ind)) - pref[ind-1];
            if(req<=x){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        cout<<ans<<endl;
    }

    return 0;
}