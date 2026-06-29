#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<char>> v(n, vector<char>(m));
        for (auto &it : v)
        {
            for (auto &itt : it)
                cin >> itt;
        }
        int count = 0;

        vector<vector<int>> pref(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == 'g')
                {
                    pref[i][j] = 1;
                    count++;
                }
                if (i > 0)
                {
                    pref[i][j] += pref[i - 1][j];
                }
                if (j > 0)
                {
                    pref[i][j] += pref[i][j - 1];
                }
                if (i > 0 && j > 0)
                {
                    pref[i][j] -= pref[i - 1][j - 1];
                }
            }
        }
        int ans = count;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == '.')
                {
                    int tot = pref[min(i + k - 1, n - 1)][min(j + k - 1, m - 1)];
                    // cout << tot << " ";
                    if (i >= k)
                    {
                        tot -= pref[i - k][min(j + k - 1, m - 1)];
                    }
                    if (j >= k)
                    {
                        tot -= pref[min(i + k - 1, n - 1)][j - k];
                    }
                    if (j >= k && i >= k)
                    {
                        tot += pref[i - k][j - k];
                    }
                    ans = min(ans, tot);
                    // cout << ans << " ";
                }
            }
        }
        // cout << endl;
        // cout << count << " " << ans << endl;
        cout << (count - ans) << endl;
    }

    return 0;
}