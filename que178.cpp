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
        long long n;
        cin >> n;
        vector<pair<long long, long long>> a(n, {0, 0});
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        long long k = 1, p = 1, time = 0;
        vector<long long> ans(n, 0);
        for (long long i = n - 1; i >= 0; i--)
        {
            ans[a[i].second] = (p == 1) ? k : (-1) * k;
            time += 2 * (abs(ans[a[i].second])) * a[i].first;
            if (p == -1)
                k++;
            p *= -1;
        }
        cout << time << endl;
        cout << 0 << " ";
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
}