#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int func(int indx, int sum, int n, vector<vector<int>> &dp)
{
    if (indx == n+1)
    {
        int another = (((n) * (n + 1)) / 2) - sum;
        if (sum == another)
            return 1;
        return 0;
    }

    if (dp[indx][sum] != -1)
        return dp[indx][sum];

    int ans = (func(indx + 1, sum, n, dp) + func(indx + 1, sum + indx, n, dp))%mod;

    return dp[indx][sum] = ans;
}

int main()
{
    int n;
    cin >> n;
    int total = ((n) * (n + 1)) / 2;

    if(total%2!=0){
        cout<<0<<endl;
        return 0;
    }

    vector<vector<int>> dp(n + 1, vector<int>(total + 1, -1));

    long long ans = func(1, 0, n, dp);
    ans = ans * 500000004LL % mod;
    cout<<ans<<endl;

    return 0;
}