#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n; cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    
    vector<ll> b(n,0);
    map<ll,ll> mp;
    ll ans = 0;
    for(ll i=0;i<=n-5;i++){
        ll currans = 0;
        ll currsum = a[i] + a[i+2] - a[i+4];
        b[i] = currsum;
        if(mp.find(currsum)!=mp.end()){
            currans = mp[currsum];
            
            if(i-2>=0 && b[i-2]==currsum) currans--;
            if(i-4>=0 && b[i-4]==currsum) currans--;

            ans += currans;
            mp[currsum]++;
        }
        else{
            mp[currsum] = 1;
        }
    }

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