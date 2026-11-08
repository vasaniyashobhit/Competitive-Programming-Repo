#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod = 998244353;
vector<ll> fact(1e4+1);

ll power(ll base, ll exp) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, mod - 2);
}

void precompute(){
    fact[0] = 1;
    fact[1] = 1;
    for(ll i=2; i<=1e4; i++){
        fact[i] = (fact[i-1] * i) % mod;
    }
} 

ll ncr(ll n, ll r){
    if(r > n || r < 0) return 0;
    
    ll num = fact[n];
    ll den = (fact[r] * fact[n-r]) % mod;
    
    return (num * modInverse(den)) % mod;
}

void solve() {
    ll n; cin>>n;
    vector<ll> a(n);
    for(auto &it:a) cin>>it;

    vector<ll> dp(n+1,0);
    vector<ll> suf(n + 1, 0);

    ll ans = 0;

    for(ll i=n-2;i>=0;i--){
        if(a[i]<=0){
            dp[i] = 0;
            suf[i] = suf[i+1];
            continue;
        }
        for(ll j=i+1;j<n;j++){
            dp[i] += (ncr(j-i-1,a[i]-1)*(suf[j+1] + 1))%mod;
        }
        suf[i] = (suf[i+1] + dp[i]) % mod;
    }

    cout<<suf[0]<<endl;
    return;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    precompute();
    while (t--) solve();

    return 0;
}