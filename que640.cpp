#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int &it:a) cin>>it;

    vector<vector<int>> dp(n+1,vector<int>(4));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=3;i++){
        dp[n][i] = 0;
    }

    for(int i=n-1;i>=0;i--){
        for(int j=3;j>=1;j--){
            
            int ans1 = a[i] + dp[i+1][j-1];
            if(j!=1) ans1 -= 1;
             
            int ans2 = dp[i+1][j];
            if(j!=3) ans2 -= 1;

            dp[i][j] = max(ans1,ans2);
        }
    }

    cout<<dp[0][3]<<endl;
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