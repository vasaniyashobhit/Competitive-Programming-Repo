#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll w,h; cin>>w>>h;

    ll k1; cin>>k1;
    vector<ll> x1(k1);
    for(ll &it:x1) cin>>it;

    ll k2; cin>>k2;
    vector<ll> x2(k2);
    for(ll &it:x2) cin>>it;

    ll k3; cin>>k3;
    vector<ll> y1(k3);
    for(ll &it:y1) cin>>it;

    ll k4; cin>>k4;
    vector<ll> y2(k4);
    for(ll &it:y2) cin>>it;

    ll ans1 = (max(x1[k1-1]-x1[0],x2[k2-1]-x2[0]))*h;
    ll ans2 = (max(y1[k3-1]-y1[0],y2[k4-1]-y2[0]))*w;

    cout<<max(ans1,ans2)<<endl;
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