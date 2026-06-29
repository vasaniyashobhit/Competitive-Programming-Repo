#include <bits/stdc++.h>
using namespace std;

int check(int ind, int rem, vector<int> &dp, vector<int> &a, int n)
{
    int ans = 0;
    // right
    if (ind == rem)
    {
        ans = (ans || dp[ind]);
        if (ind + a[ind] + 1 <= n - 1)
            ans = (ans || check(ind + a[ind] + 1, ind + a[ind] + 1, dp, a, n));
    }

    if ((ind > rem) && (ind - a[ind] == rem))
    {
        ans = (ans || dp[ind + 1]);
    }
    if (ind < n - 1)
        ans = (ans || check(ind + 1, rem, dp, a, n));
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &it : a)
            cin >> it;

        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i + a[i] > n - 1)
            {
                dp[i] = 0;
            }
            else if (i + a[i] == n - 1)
            {
                dp[i] = 1;
            }
            else
            {
                dp[i] = dp[i + a[i] + 1];
            }
        }
        int ans = check(0, 0, dp, a, n);
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}