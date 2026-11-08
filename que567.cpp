#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin>>n;
    string s; cin>>s;

    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(2,-1)));

    for(int i=n-1;i>=1;i--){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                if(i==n-1){
                    if(j==0 && k==0 && s[i]=='L') dp[i][j][k] = 1;
                    else if(j==1 && k==1 && s[i]=='R') dp[i][j][k] = 1;
                    else dp[i][j][k] = 0;

                    continue;
                }
                if(s[i]=='L') dp[i][j][k] = min(dp[i+1][0][k],dp[i+1][1][k]+1);
                else dp[i][j][k] = min(dp[i+1][0][k]+1,dp[i+1][1][k]);
            }
        }
    }

    int ans = (s[0]=='L') ? min(dp[1][1][1]+1,dp[1][0][0]) : min(dp[1][1][1],dp[1][0][0]+1);
    cout<<ans<<endl;

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