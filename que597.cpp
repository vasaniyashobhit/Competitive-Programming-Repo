#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,a,b; cin>>n>>a>>b;

    if(a == b && b == n){
        cout<<"YES"<<endl;
        return;
    }
    

    if(a+b<n-1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

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