#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long n,x; cin>>n>>x;
    long long m = 1e9+7;
    vector<long long> c(n,0);
    for(long long &it:c) cin>>it;
    sort(c.begin(),c.end());
    vector<long long> dp(x+1,0);
    dp[0] = 1;
    for(int i=1;i<=x;i++){
        dp[i] = 0;
        for(int j=0;j<n;j++){
            if(c[j]<=i) dp[i] = (dp[i] + dp[i-c[j]])%m;
        }
    }
    cout<<dp[x]<<endl;
 
    return 0;
}
