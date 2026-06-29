#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long m = 998244353;

    vector<long long> a(n + 1);
    vector<long long> b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    vector<vector<long long>> dp(n + 1, vector<long long>(3001, 0));
    for (int i = a[1]; i <= b[1]; i++)
    {
        dp[1][i] = 1;
    }

    vector<long long> pref(3001, 0);
    pref[0] = dp[1][0];
    for (int i = 1; i <= 3000; i++)
    {
        pref[i] += pref[i - 1] + dp[1][i];
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = a[i]; j <= b[i]; j++)
        {
            dp[i][j] = pref[j];
        }
        for (int j = 0; j <= 3000; j++)
        {
            pref[j] = 0;
        }
        for (int j = 0; j <= 3000; j++)
        {
            pref[j] = ((dp[i][j] % m));
            if (j > 0)
                pref[j] = ((pref[j] % m) + (pref[j - 1] % m)) % m;
        }
    }

    long long ans = 0;
    for (int j = a[n]; j <= b[n]; j++)
    {
        ans = ((ans % m) + (dp[n][j] % m)) % m;
    }
    cout << ans << endl;

    return 0;
}