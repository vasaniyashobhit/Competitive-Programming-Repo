#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,k; cin>>n>>k;
    long long m = 1e9+7;

    // vector<vector<long long>> a(2001);
    // for(int i=0;)


    vector<vector<long long>> dp(k,vector<long long>(n+1,0));
    for(int j=n;j>0;j--){
        dp[k-1][j]=1;
    }

    for(int i=k-2;i>=0;i--){
        for(int j=n;j>0;j--){
            for(int it=j;it<=n;it+=j){
                if(it%j==0){
                    dp[i][j] = ((dp[i][j]%m) + (dp[i+1][it]%m))%m;
                }
            }
        }
    }

    long long ans=0;
    for(int j=1;j<=n;j++){
        ans = ((ans%m) + (dp[0][j]%m))%m;
    }
    cout<<ans<<endl;

    return 0;
}