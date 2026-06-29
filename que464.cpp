#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> ar(n, vector<int>(m, 0));
    vector<vector<int>> al(n, vector<int>(m, 0));
    vector<vector<int>> au(n, vector<int>(m, 0));
    vector<vector<int>> ad(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m - 2; j++)
        {
            int x;
            cin >> x;
            ar[i][j] = x;
            al[i][j + 1] = x;
        }
    }
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            ad[i][j] = x;
            au[i + 1][j] = x;
        }
    }

    if (k % 2 != 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << -1 << " ";
            cout << endl;
        }
        return 0;
    }

    vector<vector<int>> dp1(n, vector<int>(m, 0));
    vector<vector<int>> dp2(n, vector<int>(m, 0));

    for (int it = 2; it <= k; it += 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                int min_val = 1e9; 

                if (j > 0)
                    min_val = min(min_val, dp1[i][j - 1] + 2 * al[i][j]);

                if (j < m - 1)
                    min_val = min(min_val, dp1[i][j + 1] + 2 * ar[i][j]);

                if (i > 0)
                    min_val = min(min_val, dp1[i - 1][j] + 2 * au[i][j]);

                if (i < n - 1)
                    min_val = min(min_val, dp1[i + 1][j] + 2 * ad[i][j]);

                dp2[i][j] = min_val;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp1[i][j] = dp2[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dp2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}