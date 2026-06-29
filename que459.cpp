#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> dp(501,vector<int>(501,0));
    for(int i=1;i<=500;i++){
        dp[i][1] = i-1;
    }
    for(int j=1;j<=500;j++){
        for(int i=1;i<=500;i++){
            // dp[i][j]
            if(j>i) dp[i][j] = dp[j][i];
            else{
                // dp[i][j] = dp[i-j][j]
                if(i-j>j) dp[i][j] = 1 + dp[i-j][j];
                else if(i==j) dp[i][j] = 0;
                else dp[i][j] = 1 + dp[j][i-j];
            }
        }
    }
    int a,b; cin>>a>>b;
    cout<<dp[a][b]<<endl;

    return 0;
}