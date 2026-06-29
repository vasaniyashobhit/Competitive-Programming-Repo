#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string a,b; cin>>a>>b;

        vector<int> dp(n+1);
        dp[n] = 0;
        if(a[n-1]==b[n-1]) dp[n-1] = 0;
        else dp[n-1] = 1;

        for(int i=n-2;i>=0;i--){
            int x;
            // i+1
            if(a[i]==b[i]) x = dp[i+1];
            else x = 1+dp[i+1];

            int y=0;
            // i+2
            if(a[i]!=a[i+1]) y++;
            if(b[i]!=b[i+1]) y++;
            y += dp[i+2];

            dp[i] = min(x,y);
        }
        
        cout<<dp[0]<<endl;

    }

    return 0;
}