#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int &it:a) cin>>it;

    vector<int> dp(1e5+1,0);
    dp[0] = 1;
    for(int i=0;i<n;i++){
        vector<int> temp(1e5+1,0);
        int num = a[i];
        for(int j=0;j<=1e5;j++){
            if(dp[j]==1) temp[j] = 1;
            if(dp[j]==1 && j+num<=1e5) temp[j+num] = 1;
        }
        dp = temp;
    }

    int sum=0;
    for(int i=1;i<=1e5;i++) if(dp[i]==1) sum++;
    cout<<sum<<endl;
    for(int i=1;i<=1e5;i++) if(dp[i]==1) cout<<i<<" ";
    cout<<endl;

    return 0;
}