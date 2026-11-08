#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<ll> a(n);
        for(auto &it:a) cin>>it;

        vector<ll> b(n);
        for(ll &it:b) cin>>it;

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        bool k = true;
        for(ll i=0;i<n;i++){
            if(a[i]<=b[i]){
                k = false;
                break;
            }
        }
        if(k==false){
            cout<<0<<endl;
            continue;
        }

        ll mod = 1e9+7;
        ll j=0;
        ll ans = 1;
        for(ll i=0;i<n;i++){
            while(j<n && b[j]<a[i]) j++;
            ans = (ans*(j-i))%mod;
        }

        cout<<ans<<endl;
    }

    return 0;
}