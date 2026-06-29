#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin>>n;
    long long m = 1e9 + 7;
    vector<long long> dp(n+1,0);
    dp[1] = 1;
    for(int i=1;i<=n;i++){
        long long cnt = 0;
        if(i>=7) cnt = 6;
        else{
            cnt = i-1;
            dp[i] = 1;
        }
        for(int j=1;j<=cnt;j++){
            dp[i] = ((dp[i]%m) + (dp[i-j]%m))%m;
        }
    }
    cout<<dp[n]<<endl;


    return 0;
}