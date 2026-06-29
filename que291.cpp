#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,m; cin>>n>>m;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        map<long long,long long> mp;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(mp.find(a[i]%m)==mp.end()){
                mp[a[i]%m]=1;
            }
            else mp[a[i]%m]++;
        }

        if(mp.find(0)!=mp.end()) ans=1;
        if(m%2==0 && mp.find(m/2)!=mp.end()) ans++;
        
        for(long long i=1;i<=m/2;i++){
            if(m%2==0 && i==m/2) break;

            if(mp.find(i)==mp.end() && mp.find(m-i)==mp.end()) continue;
            else if(mp.find(i)==mp.end() && mp.find(m-i)!=mp.end()){
                ans += mp[m-i];
                continue;
            }
            else if(mp.find(i)!=mp.end() && mp.find(m-i)==mp.end()){
                ans += mp[i];
                continue;
            }
            
            if(abs(mp[i]-mp[m-i])<=1) ans += 1;
            else{
                ans += (1 + mp[i]+mp[m-i] - (2*min(mp[i],mp[m-i]) + 1));
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}