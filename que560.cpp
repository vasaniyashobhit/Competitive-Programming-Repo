#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod = 1e9+7;

ll calc(ll n, ll prev, vector<vector<ll>> &dp, ll mod3){
    if(n==0){
        if(mod3==0) return 1;
        else return 0;
    }

    ll sum = 0;
    for(int i=0;i<=9;i++){
        if(i==prev) continue;
        if(dp[n-1][(mod3+i)%3]!=-1){
            sum = (sum + dp[n-1][(mod3+i)%3])%mod;
        }
        else{
            sum = (sum + calc(n-1,i,dp,(mod3+i)%3))%mod;
        }
    }
    // if(n==3) cout<<"hello "<<sum<<endl;
    dp[n][mod3] = sum;
    return dp[n][mod3];
}

int main(){
    ll n; cin>>n;
    vector<vector<ll>> dp(n+1,vector<ll> (3,-1));
    cout<<calc(n,-1,dp,0)<<endl;

    return 0;
}

