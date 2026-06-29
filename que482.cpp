#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin>>n;
    vector<long long> a(n);
    for(long long &it:a) cin>>it;

    vector<long long> pref(n,0);
    pref[0] = a[0];
    for(long long i=1;i<n;i++) pref[i] = a[i]+pref[i-1];

    vector<vector<long long>> dp(n,vector<long long>(n));
    
    // base case
    for(int i=0;i<n;i++){
        dp[i][i] = a[i];
    }

    for(long long i=n-2;i>=0;i--){
        for(long long j=i+1;j<n;j++){
            
            long long tot1 = pref[j];
            if(i>=0) tot1 -= pref[i];

            long long tot2 = pref[j-1];
            if(i-1>=0) tot2 -= pref[i-1]; 
            
            dp[i][j] = max(a[i]+tot1-dp[i+1][j], a[j]+tot2-dp[i][j-1]); 
        }
    }

    cout<<dp[0][n-1]<<endl;

    return 0;
}