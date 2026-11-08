#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n,x; cin>>n>>x;
    vector<ll> a(n);
    for(ll &it:a) cin>>it;

    sort(a.begin(),a.end());
    // for(auto it:a) cout<<it<<" ";
    // cout<<endl;

    int sum = 0;
    int i=0,j=n-1;
    ll ans = 0;
    vector<ll> b;
    while(i<=j){
        if((sum+a[j])>=x){
            ans += a[j];
            b.push_back(a[j]);
            sum = (sum+a[j])%x;
            j--;
        }
        else{
            sum += a[i];
            b.push_back(a[i]);
            i++;
        }
    }
    cout<<ans<<endl;
    for(auto it:b) cout<<it<<" ";
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