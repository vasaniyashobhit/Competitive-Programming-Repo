#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;
        
        vector<long long> dp(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=2*i;j<=n;j+=i){
                if(a[j-1]>a[i-1]){
                    dp[j] = max(dp[j],dp[i]+1);
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(dp[i]+1>ans) ans=dp[i]+1;
        }
        cout<<ans<<endl;
    }

    return 0;
}