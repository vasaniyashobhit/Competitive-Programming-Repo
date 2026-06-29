#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        vector<long long> suff(n,0);
        suff[n-1] = a[n-1];
        for(long long i=n-2;i>=0;i--){
            suff[i] = suff[i+1]+a[i];
        }
        vector<long long> pref(n,0);
        pref[0] = a[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]+abs(a[i]);
        }

        long long maxans = -(suff[1]);
        maxans = max(maxans,pref[n-2]);
        for(long long i=1;i<n-1;i++){
            long long ans = pref[i-1]-suff[i+1];
            maxans = max(ans,maxans);
        }
        cout<<maxans<<endl;
    }

    return 0;
}