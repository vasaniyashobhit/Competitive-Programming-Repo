#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int &it:a) cin>>it;

    int ans = 0;
    int i=n-1;
    while(i>=0 && a[i]==a[n-1]) i--;

    if(i == -1){
        cout<<0<<endl;
        return;
    }

    while(i>=0){
        i -= (n-i-1);
        ans++;
        while(i>=0 && a[i]==a[n-1]) i--;
    }

    cout<<ans<<endl;

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