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
        int n;
        cin >> n;
        vector<long long> a(n);
        for (long long &it : a)
            cin >> it;

        long long ans1 = a[0] + a[1];

        long long mini = a[0];
        long long ans2 = 0;
        vector<long long> b(n);
        for (int i = 0; i < n; i++)
        {
            if (a[i] < mini)
            {
                mini = a[i];
            }
            b[i] = mini;
        }
        for (int i = 0; i < n; i++)
        {
            ans2 += b[i];
        }
        cout << ans2 << endl;
        cout << min(ans1, ans2) << endl;
    }

    return 0;
}