#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int t; cin>>t;
    ll mod = 1e9+7;
    while(t--){
        ll n,k; cin>>n>>k;

        vector<vector<ll>> dp(k+1,vector<ll>(n+1));
        for(int i=0;i<=n;i++){
            dp[1][i] = 1;
        }

        for(int i=0;i<=k;i++){
            dp[i][0] = 1;
        }

        for(int i=2;i<=k;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = (dp[i][j-1] + dp[i-1][n-j])%mod;
            }
        }

        cout<<dp[k][n]<<endl;
    }

    return 0;
}