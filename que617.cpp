#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n; cin>>n;
    vector<ll> b(n);
    for(ll &it:b) cin>>it;

    ll sum = 0,nonzero=0;
    for(int i=0;i<n;i++){
        sum += b[i];
        if(b[i]>0) nonzero++;
    }
    ll extra = sum - n;

    if(nonzero <= extra){
        cout<<nonzero<<endl;
    }
    else{
        cout<<extra+1<<endl;
    }

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