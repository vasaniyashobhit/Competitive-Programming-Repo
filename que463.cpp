#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> a(n);
    for (int &it : a)
        cin >> it;
    vector<int> b(n);
    b[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        b[i] = (a[i] + b[i - 1]) % h;
    }
    // for(auto it:b) cout<<it<<" ";

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; i++)
    {
        int t = ((b[n - 1] - i) % h + h) % h;
        if (t >= l && t <= r)
            dp[n - 1][i] = 1;
        else
            dp[n - 1][i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int t = ((b[i] - n) % h + h) % h;
        if (t >= l && t <= r)
            dp[i][n] = 1;
        else
            dp[i][n] = 0;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int t = ((b[i] - j) % h + h) % h;
            if (t >= l && t <= r)
                dp[i][j] = 1;
            dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    // cout << max(dp[0][0], dp[0][1]) << endl;
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans = max(dp[0][i], ans);
        // cout << dp[6][i] << " ";
    }
    // cout<<endl;
    // cout<<ans<<endl;
    cout << max(dp[0][0], dp[0][1]) << endl;
    //  for(int i=0;i<=n;i++) cout<<dp[n-1][i]<<" ";

    return 0;
}