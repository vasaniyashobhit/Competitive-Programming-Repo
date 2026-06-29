#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <map>
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

        vector<long long> pref(n);
        pref[0] = a[0].first;
        for (long long i = 1; i < n; i++)
            pref[i] = pref[i - 1] + a[i].first;

        vector<long long> ans(n, 0);
        vector<long long> mainans(n, 0);
        long long i = 0, j = 0;
        while (i < n)
        {
            while (j < n - 1 && pref[j] >= a[j + 1].first)
                j++;
            for (long long k = i; k <= j; k++)
                ans[k] = j;
            i = j + 1;
            j++;
        }
        for (long long p = 0; p < n; p++)
        {
            mainans[a[p].second] = ans[p];
        }
        for (auto it : mainans)
            cout << it << " ";
        cout << endl;
    }
}