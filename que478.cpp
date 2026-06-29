#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<vector<string>> dp(n,vector<string>(n));
    dp[n-1][n-1] = a[n-1][n-1];
    for(int j=n-2;j>=0;j--){
        dp[n-1][j] = a[n-1][j] + dp[n-1][j+1];
    }
    for(int i=n-2;i>=0;i--){
        dp[i][n-1] = a[i][n-1] + dp[i+1][n-1];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            if(dp[i+1][j]<dp[i][j+1]) dp[i][j] = a[i][j] + dp[i+1][j];
            else dp[i][j] = a[i][j] + dp[i][j+1];
        }
    }

    cout<<dp[0][0]<<endl;

    return 0;
}