#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x; cin>>n>>x;
    int m = 1e9+7;
    vector<int> c(n);
    for(int &it:c) cin>>it;

    vector<vector<int>> dp(x+1,vector<int>(n,0));
    for(int j=0;j<n;j++){
        dp[0][j] = 1;
    }
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            long long skipping=0,picking=0;
            if(i-c[j]>=0) picking = (dp[i-c[j]][j]);
            if(j!=0) skipping = (dp[i][j] + dp[i][j-1]);
            dp[i][j] = (skipping+picking)%m;
        }
        
    }
    cout<<dp[x][n-1];

    return 0;
}