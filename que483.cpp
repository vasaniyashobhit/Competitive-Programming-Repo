#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;
        vector<int> dp(n,0);
        if(a[0]+0==n-1) a[n-1]=1;
        for(int i=1; i<n-1 ; i++){
            if(i-a[i]==0) dp[i] = 1;
            if(dp[i-1]==1 && i+a[i]<=n-1) dp[i+a[i]]=1;
        }
        if(dp[n-1]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;

}