#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n; cin>>n;
    vector<ll> a(n);
    for(ll &it:a) cin>>it;

    ll gcd1=0, lcm1=0;
    ll gcd2=0, lcm2=0;

    for(int i=0;i<n;i++){
        if(i%2==0){
            gcd2 = __gcd(gcd2,a[i]);
        }
        else{
            gcd1 = __gcd(gcd1,a[i]);
        }
    }

    bool k1=true,k2=true;
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(a[i]%gcd1==0) k1=false;
        }
        else{
            if(a[i]%gcd2==0) k2 = false;
        }
    }

    if(k1==true) cout<<gcd1<<endl;
    else if(k2==true) cout<<gcd2<<endl;
    else cout<<0<<endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}