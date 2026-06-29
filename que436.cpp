#include<bits/stdc++.h>
using namespace std;

int main(){
    
        int n; cin>>n;
        vector<long long> a(n);
        vector<long long> b(n);
        for(long long &it:a) cin>>it;
        for(long long &it:b) cin>>it;

        map<pair<long long,long long>,long long> mp;
        long long ans=0,ext=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                if(b[i]==0) ext++;
                continue;
            }
            long long g  =  __gcd(a[i],b[i]) ;
            b[i]/=g; a[i]/=g;
            
            pair<long long,long long> p;
            if((b[i]<0 && a[i]<0) || (b[i]>=0 && a[i]>=0)) p = {abs(b[i]),abs(a[i])};
            else p = {-abs(b[i]),abs(a[i])};

            if(mp.find(p)==mp.end()) mp[p] = 1;
            else{
                mp[p]++;
            }
            ans = max(ans,mp[p]);
        }
        cout<<ans+ext<<endl;
    

    return 0;
}