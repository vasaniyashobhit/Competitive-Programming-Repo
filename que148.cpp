#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<pair<long long, long long>> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end());
    multiset<long long> et;
    for (long long i = 0; i < k; i++)
    {
        et.insert(-1);
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++)
    {
        auto it = upper_bound(et.begin(), et.end(), a[i].second);
        if (it == et.begin())
            continue;
        ans++;
        et.erase(--it);
        et.insert(a[i].first);
    }
    cout << ans << endl;

    return 0;
}