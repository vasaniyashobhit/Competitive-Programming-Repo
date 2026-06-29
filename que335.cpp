#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;
        
        map<long long,long long> mp;
        vector<long long> b;
        for(long long i=0;i<n;i++){
            long long count=0;
            while(a[i]%2==0){
                count++;
                a[i]/=2;
            }
            if(mp.find(a[i])==mp.end()){
                b.push_back(a[i]);
                mp[a[i]] = count;
            }
            else mp[a[i]] = max(count,mp[a[i]]);
        }
        long long ans=0;
        for(long long i=0;i<b.size();i++) ans += mp[b[i]];
        cout<<ans<<endl;
    }

    return 0;
}