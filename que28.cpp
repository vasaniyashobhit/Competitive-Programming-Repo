#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool check(long long dist, long long n, vector<long long> d, long long c)
{
    c--;
    long long i = 0;
    long long j = 1;
    bool ans = true;
    while (c > 0 && j < n)
    {
        while (j < n && (d[j] - d[i]) < dist)
        {
            j++;
        }
        if (j == n)
            break;
        c--;
        i = j;
    }
    if (c == 0)
        return true;
    else
        return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, c;
        cin >> n >> c;
        vector<long long> d(n);
        for (long long &it : d)
            cin >> it;
        sort(d.begin(), d.end());

        long long l = 0, r = d[n - 1];
        long long ans = -1;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            if (check(mid, n, d, c))
            {
                ans = mid;
                l = mid + 1;
                // cout << ans << " ";
            }
            else
            {
                r = mid - 1;
            }
        }
        // cout << endl;
        cout << ans << endl;
    }

    return 0;
}