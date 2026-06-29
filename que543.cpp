#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    vector<int> opnum(1e3+1,1e8);
    opnum[1] = 0;
    opnum[2] = 1;
    for(int i=2;i<=1e3;i++){
        for(int j=1;j<=i;j++){
            int pos = i + i/j;
            if(pos<=1e3) opnum[pos] = min(opnum[pos],opnum[i]+1);
        }
    }

    while(t--){
        int n,k; cin>>n>>k;
        vector<int> b(n);
        vector<int> c(n);
        int maxc = 0;
        for(int &it:b) cin>>it;
        for(int &it:c) cin>>it;

        int opsum = 0;
        vector<int> op(n);
        for(int i=0;i<n;i++){
            op[i] = opnum[b[i]];
            opsum += op[i];
        }

        if(k>=opsum){
            int sum = 0;
            for(int i=0;i<n;i++) sum += c[i];
            cout<<sum<<endl;
            continue;
        }

        vector<vector<int>> dp(n, vector<int>(k+1));

        for(int j=0;j<=k;j++){
            if(j>=op[n-1]) dp[n-1][j] = c[n-1];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=k;j++){
                dp[i][j] = dp[i+1][j];
                if(j-op[i]>=0) dp[i][j] = max(dp[i+1][j-op[i]]+c[i],dp[i][j]);
            }
        }
        cout<<dp[0][k]<<endl;

    }

    return 0;
}