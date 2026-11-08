#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n,m; cin>>n>>m;
    vector<ll> a(n);
    for(ll &it:a) cin>>it;

    vector<ll> b(m);
    for(ll &it:b) cin>>it;
    sort(b.begin(),b.end());

    vector<ll> pref(n,0);
    pref[0] = a[0];
    for(ll i=1;i<n;i++) pref[i] = pref[i-1]+a[i];

    

    ll sum = abs(pref[b[0]-1]);
    for(int i=1;i<m;i++){
        sum += abs(pref[b[i]-1]-pref[b[i-1]-1]);
    }

    if(b[m-1]!=n){
        sum += pref[n-1] - pref[b[m-1]-1];
    }
    cout<<sum<<endl;

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