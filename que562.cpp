#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    ll costa, costb; cin>>costa>>costb;
    vector<ll> swc(n-1);
    for(ll &it:swc) cin>>it;

    if(n==1){
        cout<<min(costa,costb)<<endl;
        return 0;
    }
    else if(n==2){
        ll ans1 = min(costa+costa,costa+costb+swc[0]);
        ll ans2 = min(costa+costb+swc[0],costb+costb);
        cout<<min(ans1,ans2)<<endl;
        return 0;
    }

    vector<vector<ll>> dp(n+1,vector<ll>(4,-1));

    // basecase
    for(int j=0;j<4;j++){
        dp[0][j] = 0;
    }

    for(int i=1;i<=n-2;i++){
        for(int j=0;j<4;j++){
            if(j==0){
                dp[i][j] = (dp[i-1][1]+costb+swc[n-i-1]);
            }
            else if(j==1){
                dp[i][j] = min(dp[i-1][2]+costa+swc[n-i-1],dp[i-1][3]+costb);
            }
            else if(j==2){
                dp[i][j] = min(dp[i-1][0]+costa,dp[i-1][1]+costb+swc[n-i-1]);
            }
            else{
                dp[i][j] = (dp[i-1][2]+costa+swc[n-i-1]);
            }
        }
    }

    ll ans1 = min(dp[n-2][0]+(2*costa), dp[n-2][1]+costa+costb+swc[0]);
    ll ans2 = min(dp[n-2][2]+costa+costb+swc[0],dp[n-2][3]+costb+costb);
    cout<<min(ans1,ans2)<<endl;

    return 0;
}