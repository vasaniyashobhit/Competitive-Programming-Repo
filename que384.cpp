#include<bits/stdc++.h>
using namespace std; 

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        vector<int> dp(n+1,n);
        dp[n] = 0;
        dp[n-1] = 1;
        for(int i = n-2; i>=0;i--){
            int ans1,ans2;
            if(i+a[i]>n-1){
                ans1 = n-i;
            }
            else if(i+a[i]==n-1){
                ans1 = 0;
            }
            else{
                ans1 = dp[i+a[i]+1];
            }
            ans2 = 1 + dp[i+1];
            dp[i] = min(ans1,ans2);
        }
        cout<<dp[0]<<endl;
    }
    return 0;
}