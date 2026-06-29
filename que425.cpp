#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,m; cin>>n>>m;
    long long mod = 1e9+7;
    vector<long long> a(n);
    for(long long &it:a) cin>>it;

    vector<vector<long long>> dp(n,vector<long long> (m+1,0));
    vector<long long> ans(n,0);
    bool valid = true;
    if(a[0]==0){
        for(int j=1;j<=m;j++){
            dp[0][j] = 1;
        }
        ans[0] = m;
    }
    else{
        ans[0] = 1;
    }

    for(int i=1;i<n;i++){
        if(a[i]!=0 && a[i-1]!=0 && abs(a[i]-a[i-1])>1){
            valid = false;
            break;
        }

        if(a[i]!=0 && a[i-1]!=0){
            ans[i] = ans[i-1];
        }
        else if(a[i]!=0 && a[i-1]==0){
            for(int j=1;j<=m;j++){
                if(abs(a[i]-j)<=1) ans[i] = ( (ans[i]%mod) + (dp[i-1][j]%mod))%mod;
            }
        }
        else if(a[i]==0 && a[i-1]!=0){
            for(int j=1;j<=m;j++){
                if(abs(a[i-1]-j)<=1){
                    dp[i][j] = ans[i-1];
                    ans[i] = ((ans[i]%mod)+(ans[i-1]%mod))%mod;
                }
            }
        }
        else{
            for(int j=1;j<=m;j++){
                if(j>1) dp[i][j] = ((dp[i][j]%mod) + (dp[i-1][j-1]%mod))%mod;
                dp[i][j] = ((dp[i][j]%mod) + (dp[i-1][j]%mod))%mod;
                if(j<m) dp[i][j] = ((dp[i][j]%mod) + (dp[i-1][j+1]%mod))%mod;

                ans[i] = ((ans[i]%mod) + (dp[i][j]%mod))%mod;
            }
        }
        if(ans[i]==0){
            valid = false;
            break;
        }
    }
    if(valid==false) cout<<0<<endl;
    else cout<<ans[n-1]<<endl;
    //cout<<ans[n-1]<<endl;
    return 0;
}