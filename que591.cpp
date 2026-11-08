#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int &it:a) cin>>it;

    int xorall = 0;
    for(int i=0;i<n;i++) xorall = xorall^a[i];

    if(n%2==0 && xorall!=0) cout<<-1<<endl;
    else cout<<xorall<<endl;

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