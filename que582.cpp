#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll calc(ll prev, int selected, vector<vector<ll>> &rules, vector<ll> &a, vector<vector<ll>> &dp, ll m){
    ll n = a.size();

    if(__builtin_popcount(selected)==m) return 0;
    
    if(dp[prev][selected]!=-1) return dp[prev][selected];

    ll mx = 0;
    for(ll i=0;i<n;i++){
        
        if(((selected>>i)&1)==0){
            
            ll currscore = a[i];

            if(prev != n) currscore += rules[prev][i];
        
            currscore += calc(i,selected|(1<<i),rules,a,dp,m);
            mx = max(currscore,mx);
        }
    }

    return dp[prev][selected] = mx;
}

void solve() {
    ll n,m,k; cin>>n>>m>>k;

    vector<ll> a(n);
    for(ll &it:a) cin>>it;

    vector<vector<ll>> rules(n,vector<ll>(n,0));
    for(int i=0;i<k;i++){
        ll x,y,c; cin>>x>>y>>c;
        x--;y--;
        rules[x][y] = c;
    }

    vector<vector<ll>> dp(n+1,vector<ll>(1<<n,-1));

    ll selected = 0;
    
    ll ans = calc(n,selected,rules,a, dp, m);

    cout<<ans<<endl;
}

int main() {

    int t=1;
    while (t--) solve();

    return 0;
}