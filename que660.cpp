#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(ll least, ll op, vector<vector<ll>> &a, ll n){
    ll reqop = 0;
    for(ll i=0;i<n;i++){

        ll currsum = a[i][0]+a[i][1]+a[i][2];

        if(currsum<least && a[i][0]<=a[i][2] && a[i][1]<=a[i][2] && a[i][0]<=a[i][1]){
            if(a[i][0]==a[i][1] && a[i][1]==a[i][2]) return false;
            ll extra = a[i][2] - max(a[i][0],a[i][1]) + 1ll;
            extra = min(extra,a[i][1]-a[i][0]+1ll);
            reqop += extra + (least - (currsum-extra));
        }
        else if(currsum<least) reqop += least-currsum;

        if(reqop>3*1e18) return false;
    }


    if(reqop > op) return false;
    return true;
}

void solve() {
    ll n,k; cin>>n>>k;
    vector<vector<ll>> a(n,vector<ll>(3,0));
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }

    ll l = -1e10, r = 2*1e18;
    ll ans = -1e10;
    while(l<=r){
        ll mid = l + (r-l)/2;
        if(check(mid,k,a,n)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }

    cout<<ans<<endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}