#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,x; cin>>n>>x;
    vector<long long> c(n);
    for(long long &it:c) cin>>it;
    sort(c.begin(),c.end());

    long long inf = 1e7;
    vector<long long> dp(x+1,0);
    vector<bool> check(n+1,false);
    dp[0] = 0;
    for(long long i=1;i<=x;i++){
        if(c[0]>i){
            dp[i] = inf;
            continue;
        }
        long long sm = inf; 
        for(int j=0;j<n;j++){
            if(i-c[j]>=0) sm = min(sm,dp[i-c[j]]);
        }
        dp[i] = 1+sm;
    }
    if(dp[x]>=inf) cout<<-1<<endl;
    else cout<<dp[x]<<endl;


}