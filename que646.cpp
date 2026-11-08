#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n,m; cin>>n>>m;
    vector<ll> a(n);
    for(ll &it:a) cin>>it;

    ll sum = 0;
    for(int i=n-1;i>=1;i--){
        if(a[i]==a[i-1]){
            sum += n-i;
        }
        else{
            sum += (i+1)*(n-i);
        }
    }
    sum += n;

    //cout<<"hello "<<sum<<endl;

    while(m--){
        ll i,x; cin>>i>>x;
        i--;
        if(a[i]==x) cout<<sum<<endl;
        else{
            if(i>0 && x==a[i-1]){
                sum = sum - (i+1)*(n-i) + (n-i);
            }
            else if(i>0 && a[i]==a[i-1]){
                sum = sum - (n-i) + (i+1)*(n-i);
            }

            if(i<n-1 && x==a[i+1]){
                ll j = i+1;
                sum = sum - (j+1)*(n-j) + (n-j);
            }
            else if(i<n-1 && a[i]==a[i+1]){
                ll j = i+1;
                sum = sum - (n-j) + (j+1)*(n-j);
            }

            cout<<sum<<endl;
        }

        a[i] = x;
    }

    return;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t=1;
    while (t--) solve();

    return 0;
}