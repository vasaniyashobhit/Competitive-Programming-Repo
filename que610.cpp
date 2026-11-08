#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n,m; cin>>n>>m;
    vector<ll> a(n);
    for(ll &it:a) cin>>it;

    int maxlen = 1,len=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]) len++;
        else{
            maxlen = max(len,maxlen);
            len = 1;
        }
    }
    maxlen = max(len,maxlen);

    if(maxlen>=m) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

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