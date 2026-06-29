#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<pair<long long, long long>> a(n, {0, 0});
        for (long long i = 0; i < n; i++)
            cin >> a[i].first;
        for (long long i = 0; i < n; i++)
            cin >> a[i].second;

        for (int i = 0; i < n; i++)
        {
            if (a[i].first > a[i].second)
            {
                swap(a[i].first, a[i].second);
            }
        }
        sort(a.begin(), a.end());
        long long maxend = a[0].second;
        bool kk = false;
        for (long long i = 1; i < n; i++)
        {
            long long start = a[i].first;
            long long end = a[i].second;

            if (start <= maxend)
            {
                kk = true;
                break;
            }

            maxend = max(maxend, end);
        }

        // for (auto it : a)
        //     cout << it.first << " ";
        // cout << endl;
        // for (auto it : a)
        //     cout << it.second << " ";
        // cout << endl;

        long long ans = 0;
        for (long long i = 0; i < n; i++)
        {
            ans += abs(a[i].second - a[i].first);
        }

        // cout << kk << " ";

        if (kk == false)
        {
            long long mindiff = __LONG_LONG_MAX__;
            for (int i = 0; i < n - 1; i++)
            {
                long long difff = abs(a[i].first - a[i + 1].first) + abs(a[i].second - a[i + 1].second);
                long long diffe = abs(a[i].first - a[i].second) + abs(a[i + 1].first - a[i + 1].second);
                long long diff = abs(difff - diffe);
                mindiff = min(diff, mindiff);
                // cout << mindiff << " ";
            }
            // cout << endl;
            ans += mindiff;
            cout << ans << endl;
        }
        else
        {
            // cout << kk << " " << ans << endl;
            cout << ans << endl;
        }
    }

    return 0;
}