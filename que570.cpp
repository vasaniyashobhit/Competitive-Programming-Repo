#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,k; cin>>n>>k;
    vector<ll> a(n);
    for(ll &it:a) cin>>it;

    ll sum = 0;
    for(int i=0;i<k;i++) sum += a[i];

    ll totalsum = sum;
    for(int i=k;i<n;i++){
        sum += a[i];
        sum -= a[i-k];
        totalsum += sum;
    }

    double tsum = totalsum,weeks = n-k+1;
    cout<<fixed<<setprecision(7);
    cout<<totalsum/weeks<<endl;

    return;

}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    while (t--) solve();

    return 0;
}