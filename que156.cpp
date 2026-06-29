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
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n, {0, 0});
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a[i].first = x;
            a[i].second = -1 * (i + 1);
        }
        for (int i = 0; i < n; i++)
        {
            a[i].first %= k;
            if (a[i].first == 0)
                a[i].first = k;
        }
        sort(a.begin(), a.end());
        for (int i = n - 1; i >= 0; i--)
        {
            cout << (-1 * (a[i].second)) << " ";
        }
        cout << endl;
    }

    return 0;
}