#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    long long m = 1e9+7;
    vector<vector<char>> g(n,vector<char>(n));
    for(auto &it:g){
        for(auto &itt:it) cin>>itt;
    }

    if(g[0][0]=='*' || g[n-1][n-1]=='*'){
        cout<<0<<endl;
        return 0;
    }

    vector<vector<long long>> dp(n,vector<long long>(n,0));
    dp[n-1][n-1] = 1; // base case
    for(int j=n-2;j>=0;j--){  // base row
        if(g[n-1][j]=='*') dp[n-1][j] = 0;
        else dp[n-1][j] = dp[n-1][j+1];
    }
    for(int i=n-2;i>=0;i--){  // base column
        if(g[i][n-1]=='*') dp[i][n-1] = 0;
        else dp[i][n-1] = dp[i+1][n-1];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            if(g[i][j]=='*') dp[i][j] = 0;
            else dp[i][j] = (dp[i+1][j] + dp[i][j+1])%m;
        }
    }

    cout<<dp[0][0]<<endl;

    return 0;
}