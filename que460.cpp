#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    vector<vector<double>> dp(n + 1, vector<double>(n + 1)); // dp[coins][heads]
    dp[0][0] = 1;
    for (int h = 1; h <= n; h++)
    {
        dp[0][h] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int h = 0; h <= n; h++)
        {
            dp[i][h] = dp[i - 1][h] * (1.0 - p[i]);
            if (h > 0)
                dp[i][h] += dp[i - 1][h - 1] * p[i];
        }
    }

    double ans = 0;
    for (int h = (n / 2) + 1; h <= n; h++)
    {
        ans += dp[n][h];
    }
    cout << setprecision(10) << ans << endl;

    return 0;
}