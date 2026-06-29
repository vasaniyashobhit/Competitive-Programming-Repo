#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long> a, vector<long long> b, long long dist)
{
    long long n = a.size();
    bool ans = true;
    for (long long i = 0; i < n; i++)
    {
        long long d;
        auto itr = lower_bound(b.begin(), b.end(), a[i]);
        if (itr == b.end())
        {
            d = a[i] - b[b.size() - 1];
            // cout << d << " ";
        }
        else if (itr == b.begin())
        {
            d = abs(a[i] - *(itr));
            // cout << d << " ";
        }
        else
        {
            d = min(abs(*(itr)-a[i]), abs(a[i] - *(itr - 1)));
            // cout << d << " ";
        }
        // cout << d << " ";
        if (d > dist)
        {
            ans = false;
            break;
        }
    }
    if (ans == true)
        return true;
    else
        return false;
}

void solve()
{
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (auto &it : a)
        cin >> it;
    vector<long long> b(m);
    for (auto &it : b)
        cin >> it;

    long long l = 0, r = 1e10;
    long long ans = -1;
    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        if (check(a, b, mid))
        {
            ans = mid;
            // cout << ans << " ";
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();

    return 0;
}