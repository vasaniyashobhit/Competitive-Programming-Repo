#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod = 1e9+7;

int main(){
    ll n; cin>>n;
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(3,vector<ll>(10,0)));
    
    // base case
    for(ll j=0;j<3;j++){
        for(ll k=0;k<=9;k++){
            dp[0][j][k] = (j==0) ? 1 : 0; 
        }
    }

    for(ll i=1;i<=n;i++){
        for(ll j=0;j<3;j++){
            for(ll k=0;k<=9;k++){
                dp[i][j][k] = 0;
                for(ll it=0;it<=9;it++){
                    if(it==k) continue;
                    dp[i][j][k] = (dp[i][j][k] + dp[i-1][(j+it)%3][it])%mod;
                }
            }
        }
    }

    long long ans=0;
    for(ll i=0;i<=9;i++){
        ans = (ans + dp[n-1][i%3][i])%mod;
    }
    cout<<ans<<endl;

    return 0;
}