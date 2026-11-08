#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll inf = 1e18;

void solve() {
    ll n,m,kk; cin>>n>>m>>kk;
    vector<ll> c(n);
    for(ll &it:c) cin>>it;

    vector<vector<int>> p(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>p[i][j];
    }

    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(kk+2,vector<ll>(m+1,inf)));

    // base case
    for(int k=0;k<=m;k++){
        dp[n][kk][k]=0;
    }

    for(int i=n-1;i>=0;i--){
        for(int j=kk;j>=0;j--){
            for(int k=0;k<=m;k++){
                if(c[i]!=0){
                    int curcolor = c[i];
                    int nextj = (curcolor == k) ? j : j+1;
                    if(nextj <= kk) dp[i][j][k] = dp[i+1][nextj][curcolor];
                    
                }
                else{
                    for(int curcolor = 1; curcolor<=m; curcolor++){
                        int nextj = (curcolor==k) ? j : j+1;
                        if(nextj <= kk) dp[i][j][k] = min(dp[i][j][k], dp[i+1][nextj][curcolor] + p[i][curcolor - 1]);
                    }
                }
                
            }
        }
    }
    if(dp[0][0][0]>=1e11) cout<<-1<<endl;
    else cout<<dp[0][0][0]<<endl;

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