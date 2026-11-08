#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,m; cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>a[i][j];
    }

    vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(m,{0,0}));  // {max,min}
    dp[0][0].first = a[0][0];
    dp[0][0].second = a[0][0];
    for(int i=1;i<n;i++){
        dp[i][0].first = a[i][0] + dp[i-1][0].first;
        dp[i][0].second = a[i][0] + dp[i-1][0].second;
    }
    for(int j=1;j<m;j++){
        dp[0][j].first = a[0][j] + dp[0][j-1].first;
        dp[0][j].second = a[0][j] + dp[0][j-1].second;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j].first =  a[i][j] + max(dp[i-1][j].first,dp[i][j-1].first);
            dp[i][j].second =  a[i][j] + min(dp[i-1][j].second,dp[i][j-1].second);
        }
    }

    if(dp[n-1][m-1].second>0 || dp[n-1][m-1].first<0 || (n+m)%2==0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

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