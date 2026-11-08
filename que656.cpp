#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n; cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(ll &it:a) cin>>it;
    for(ll &it:b) cin>>it;

    vector<ll> pref(n+1,0);
    ll sum = 0;
    for(int i=1;i<n;i++){
        sum += (a[i-1]==b[i-1]) ? 2 : 1 ;
        sum += (b[i-1]==a[i]) ? 2 : 1 ;
        pref[i] = sum;
    }

    vector<ll> suff(n+1,0);
    suff[n-1] = (a[n-1]==b[n-1]) ? 2 : 1 ;
    sum = suff[n-1];
    for(ll i=n-2;i>=0;i--){
        sum += (a[i]==b[i+1]) ? 2 : 1 ;
        sum += (b[i]==a[i+1]) ? 2 : 1 ;
        suff[i] = sum;
    }

    ll maxans = 0;
    for(ll i=0;i<n;i++){
        maxans = max(pref[i]+suff[i],maxans);
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