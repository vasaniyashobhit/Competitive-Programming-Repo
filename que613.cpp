#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll p,q; cin>>p>>q;

    if(p>=q){
        cout<<"Alice"<<endl;
        return;
    }

    ll currgap = q-p;
    ll gap;
    if(p%2==0){
        gap = p/2;
    }
    else gap = (p-1)/2;

    if(currgap>gap) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;

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