#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n,k; cin>>n>>k;
    vector<ll> a(n);
    for(ll &it:a) cin>>it;

    vector<ll> hash(n+1,0);
    for(ll i=0;i<n;i++){
        hash[a[i]]++;
    }
    bool pos = true;
    for(ll i=0;i<=n;i++){
        if(hash[i]%k!=0) pos = false;
    }
    if(pos==false){
        cout<<0<<endl;
        return;
    }

    map<ll,ll> mp;
    ll l = n-1;
    ll ans = 0;
    for(ll i=n-1;i>=0;i--){
        if(mp.find(a[i])==mp.end()) mp[a[i]] = 1;
        else mp[a[i]]++;
        ll cnt = hash[a[i]]/k;
        if(mp[a[i]]<=cnt) ans += l-i+1;
        else{
            
            while(mp[a[i]]>cnt){
                mp[a[l]]--;
                l--;
            }
            ans += l-i+1;
        }
        //cout<<i<<"-"<<l<<"-"<<cnt<<" ";
    }
    //cout<<endl;

    cout<<ans<<endl;
    return;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}