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
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for (int &it : a)
            cin >> it;

        sort(a.begin(), a.end());

        if (n == 1)
        {
            cout << abs(s - a[0]) << endl;
            continue;
        }
        int sum = a[n - 1] - a[0];
        if (s <= a[n - 1] && s >= a[0])
        {
            sum += min(abs(s - a[0]), abs(a[n - 1] - s));
        }
        else
        {
            sum += min(abs(a[0] - s), abs(a[n - 1] - s));
        }

        cout << sum << endl;
    }

    return 0;
}