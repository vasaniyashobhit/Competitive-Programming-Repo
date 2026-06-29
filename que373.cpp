#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,k; cin>>n>>k;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        map<long long,long long> mp;
        for(long long i=0;i<n;i++){
            if(mp.find(a[i]%k)==mp.end()) mp[a[i]%k]=1;
            else mp[a[i]%k]++;
        }

        long long maximum=0;
        for(long long i=0;i<n;i++){
            if((mp[a[i]%k]>=maximum) && (a[i]%k!=0)) maximum = mp[a[i]%k];
        }

        long long ans = (maximum-1)*k;
        long long minind = 1e9 + 1;
        for(long long i=0;i<n;i++){
            if((a[i]%k)<minind && (mp[a[i]%k]==maximum) && (a[i]%k!=0)) minind = a[i]%k;
        }

        if(maximum==0){
            cout<<0<<endl;
            continue;
        }

        //cout<<ans<<" "<<minind<<endl;
        ans += k-(minind-1);
        cout<<ans<<endl;
        
    }

    return 0;
}