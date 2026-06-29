#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    long long m = 1e9+7;

    vector<long long> fact(1e6,1);
    for(long long i=1;i<1e6;i++){
        fact[i] = ((i%m)*(fact[i-1]%m))%m;
    }
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;
        
        map<long long,long long> mp;
        for(long long i=0;i<n;i++){
            if(mp.find(a[i])==mp.end()) mp[a[i]]=1;
            else mp[a[i]]++;
        }

        vector<long long> bits(32,0);
        for(long long i=0;i<n;i++){
            for(long long j=0;j<32;j++){
                if(((a[i]>>j)&1)==1){
                    bits[j]++;
                }
            }
        }

        long long x=0;
        for(long long j=0;j<32;j++){
            if(bits[j]==n) x = (x|(1<<j));
        }

        if((mp.find(x)==mp.end()) || (mp[x]<=1)){
            cout<<0<<endl;
            continue;
        }
        else{
            long long cnt = mp[x];
            long long ans = ((fact[n-2]%m))%m;
            ans = ((ans%m)*(cnt%m))%m;
            ans = ((ans%m)*((cnt-1ll)%m))%m;
            cout<<ans<<endl;
        }
    }
}