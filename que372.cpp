#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long a,b,k; cin>>a>>b>>k;
        vector<pair<long long,long long>> v(k);
        for(int i=0;i<k;i++) cin>>v[i].first;
        for(int i=0;i<k;i++) cin>>v[i].second;
        
        vector<long long> hashg(b+1,0);
        vector<long long> hashb(a+1,0);
        for(int i=0;i<k;i++){
            hashb[v[i].first]++;
            hashg[v[i].second]++;
        }

        sort(v.begin(),v.end());

        long long ans=0,total=k;
        for(int i=0;i<k;i++){
            ans += total - hashb[v[i].first] - (hashg[v[i].second]-1);
            hashg[v[i].second]--;
            if(v[i+1].first != v[i].first) total -= hashb[v[i].first];
        }
        cout<<ans<<endl;

    }

    return 0;
}