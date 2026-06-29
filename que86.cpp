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
        long long n, x;
        cin >> n >> x;
        vector<long long> a(n);
        for (long long &it : a)
            cin >> it;

        sort(a.begin(), a.end());
        long long i;
        long long ans = 0;
        auto it = lower_bound(a.begin(), a.end(), x);
        if (it != a.end())
        {
            it--;
            i = n - 1;
        }
        else
        {
            i = it - a.begin();
            i--;
            ans = n - i - 1;
        }

        long long count = 0;
        long long min;
        while (i >= 0)
        {
            min = a[i];
            count++;
            if (min * count >= x)
            {
                ans++;
                // cout << i << " " << count << " " << min << " " << endl;
                count = 0;
            }
            i--;
        }
        // cout << endl;
        cout << ans << endl;
    }

    return 0;
}