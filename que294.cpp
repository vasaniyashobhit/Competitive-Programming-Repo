#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        long long ans=0;
        map<long long, long long> mp;
        for(int i=0;i<n;i++){
            int ind=-1;
            for(int j=0;j<=30;j++){
                if(((a[i]>>j)&1)==1) ind=j;
            }
            if(mp.find(ind)!=mp.end()){
                ans += mp[ind];
                mp[ind]++;
            }
            else mp[ind] = 1;
        }
        cout<<ans<<endl;
    }

    return 0;
}