#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n,m; cin>>n>>m;
    vector<ll> a(n+1,1);
    for(ll i=0;i<m;i++){
        ll u,v; cin>>u>>v;
        if(u>v) swap(u,v);
        a[v] = max(a[v],u+1);
    }
    for(ll i=2;i<=n;i++){
        a[i] = max(a[i],a[i-1]);
    }

    ll ans = 0;
    for(ll i=1;i<=n;i++){
        ans += (i-a[i]+1ll);
    }
    cout<<ans<<endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}