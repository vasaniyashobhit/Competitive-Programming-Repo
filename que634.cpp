#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n; cin>>n;
    vector<ll> a(n);
    for(ll &it:a) cin>>it;

    vector<ll> ans(n,0);
    for(int i=1;i<n-1;i++){
        ans[i] = (a[i-1]-2*(a[i])+a[i+1])/2;
    } 

    ll sum = a[0];
    for(int i=0;i<n-1;i++){
        sum -= ans[i]*i;
    }
    ans[n-1] = sum/(n-1);
    sum = a[n-1];
    ll k = 0;
    for(int i=n-1;i>0;i--){
        sum -= k*(ans[i]);
        k++;
    }
    ans[0] = sum/(n-1);

    for(auto it:ans) cout<<it<<" ";
    cout<<endl;
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