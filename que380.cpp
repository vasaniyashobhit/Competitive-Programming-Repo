#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<pair<long long,long long>> a(n);
    for(int i=0;i<n;i++) cin>>a[i].first;
    for(int i=0;i<n;i++) cin>>a[i].second;

    if(n==1){
        cout<<max(a[0].first,a[0].second)<<endl;
        return 0;
    }

    vector<vector<long long>> dp(n,vector<long long>(2));
    dp[n-1][0] = a[n-1].first;
    dp[n-1][1] = a[n-1].second;
    dp[n-2][0] = a[n-2].first + a[n-1].second;
    dp[n-2][1] = a[n-2].second + a[n-1].first;

    for(int i=n-3;i>=0;i--){
        dp[i][0] = a[i].first + max(max(dp[i+2][0],dp[i+2][1]),dp[i+1][1]);
        dp[i][1] = a[i].second + max(max(dp[i+2][0],dp[i+2][1]),dp[i+1][0]);
    }

    cout<<max(dp[0][0],dp[0][1])<<endl;

    return 0;
}