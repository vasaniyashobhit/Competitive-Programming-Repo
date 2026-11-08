#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod = 1e9+7;

void solve() {
    ll n,k; cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<vector<ll>> hash(n+1,vector<ll>(64,0));
    hash[0][a[0]] = 1;

    for(int i=1;i<n;i++){
        
        for(int j=0;j<=63;j++) hash[i][j] = hash[i-1][j];

        for(int j=0;j<=63;j++) hash[i][j & a[i]] = (hash[i][j & a[i]] + hash[i-1][j]) % mod;
        
        hash[i][a[i]] = (hash[i][a[i]] + 1) % mod;
    }

    long long ans = 0;
    for(int i=0;i<=63;i++){
        if(__builtin_popcount(i)==k) ans = (ans + hash[n-1][i]) % mod;
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