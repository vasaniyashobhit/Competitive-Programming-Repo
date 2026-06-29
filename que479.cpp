#include<bits/stdc++.h>
using namespace std;


int main(){
    int a,b; cin>>a>>b;

    vector<vector<int>> dp(a+1,vector<int>(b+1));
    
    // base case
    for(int i=1;i<=a;i++) dp[i][1] = (i-1);

    for(int j=1;j<=b;j++) dp[1][j] = (j-1);

    for(int i=2;i<=a;i++){
        for(int j=2;j<=b;j++){
            if(i==j){
                dp[i][j] = 0;
                continue;
            }
            int mini = 1e9;
            for(int k=1;k<=j/2;k++){
                mini = min(mini,dp[i][k]+dp[i][j-k]);
            }
            for(int k=1;k<=i/2;k++){
                mini = min(mini,dp[k][j]+dp[i-k][j]);
            }
            dp[i][j] = 1 + mini;
        }
    }

    cout<<dp[a][b]<<endl;

    return 0;
}