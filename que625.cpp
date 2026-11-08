#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n; cin>>n;
    vector<ll> a(n);
    for(ll &it:a) cin>>it;

    ll sum = 0;
    ll ext = 0;
    ll caninclude = 0;
    ll clubitems = 0;
    bool k = false;
    for(int i=0;i<n;i++){
        if(a[i]>=2){
            sum += a[i];
            clubitems++;
        }
        else ext++;

        if(a[i]>=4){
            caninclude += (a[i]-2)/2; 
        }

        if(a[i]>=3) k = true;
    }
    if(clubitems==1) caninclude++;
    sum += min(ext,caninclude);
    if(2*clubitems+ext<3 && sum<3){
        cout<<0<<endl;
        return;
    }
    cout<<sum<<endl;

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