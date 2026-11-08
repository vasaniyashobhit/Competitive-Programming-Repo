#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n,m; cin>>n>>m;
    vector<vector<ll>> a(n,vector<ll>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    ll l = 1,r = n*m;
    while(l<=m){
        
    }
}



int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}