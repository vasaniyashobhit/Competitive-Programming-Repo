#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin>>n;
    int num = n+1;
    bool ans = true;
    for(int i=2;i*i<=num;i++){
        if(num%i==0) ans = false;
    }

    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}