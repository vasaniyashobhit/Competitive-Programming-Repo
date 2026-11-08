#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n; cin>>n;
    vector<ll> a(n);
    for(ll &it:a) cin>>it;

    ll maxans = 0;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            ll ans = a[i]^a[j];
            maxans = max(ans,maxans);
        }
    }

    cout<<maxans<<endl;
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