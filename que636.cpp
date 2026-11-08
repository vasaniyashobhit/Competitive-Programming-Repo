#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n,h,k; cin>>n>>h>>k;
    vector<ll> a(n);
    for(ll &it:a) cin>>it;

    ll sum = 0;
    for(int i=0;i<n;i++) sum += a[i];

    //cout<<sum<<endl;

    ll time = 0;
    if(sum<h){
        time += (h/sum)*n;
        time += ((h/sum)-1)*k;
        if(h%sum!=0) time += k;
        h = h%sum;
    }

    if(h==0){
        cout<<time<<endl;
        return;
    }

    vector<ll> prefmax(n,0);
    prefmax[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--){
        prefmax[i] = max(a[i],prefmax[i+1]);
    }

    //cout<<time<<"-"<<h<<endl;

    ll total = 0,m=1e18,afterswap;
    for(int i=0;i<n;i++){
        total += a[i];
        afterswap = total;
        m = min(m,a[i]);
        if(i<n-1) afterswap = max(total,total-m+prefmax[i+1]);
        //cout<<afterswap<<"-";
        if(afterswap>=h){
            time += i+1;
            break;
        }
    }
    //cout<<endl;
    cout<<time<<endl;

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