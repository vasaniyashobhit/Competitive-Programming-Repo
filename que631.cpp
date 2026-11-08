#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int &it:a) cin>>it;

    int ans = 1;
    int i=0,j=1;
    while(j<n){
        if(a[j]>a[j-1]+1 || a[j]<=a[i]){
            i = j;
            j++;
            ans++;
        }
        else j++;
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