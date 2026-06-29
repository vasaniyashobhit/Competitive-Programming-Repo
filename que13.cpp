#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        vector<vector<long long>> v(m, vector<long long>(n));
        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < m; j++)
            {
                cin >> v[j][i];
            }
        }
        // for (auto it : v)
        // {
        //     for (auto itt : it)
        //         cout << itt << " ";
        //     cout << endl;
        // }
        long long rns = 0;
        long long ans = 0;
        for (long long i = 0; i < m; i++)
        {
            sort(v[i].begin(), v[i].end());
            rns = 0;
            for (long long j = 0; j < n; j++)
            {
                rns += (v[i][j]) * (n - j - 1);
                rns -= (v[i][j]) * (j);
            }
            ans += abs(rns);
        }
        cout << ans << endl;
    }
}