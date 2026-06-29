#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    
    vector<int> dp(n+1);
    dp[0] = 0;
    for(int i=1;i<=min(9,n);i++) dp[i] = 1;

    for(int i=10;i<=n;i++){
        int num = i;
        int maxint = 0; 
        while(num>0){
            maxint = max(maxint,num%10);
            num /= 10;
        }
        dp[i] = 1+dp[i-maxint];
    }

    cout<<dp[n]<<endl;


    return 0;
}