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
        vector<long long> a(n);
        for (long long &it : a)
            cin >> it;
        // sort(a.begin(), a.end());

        long long ans = 0;
        for (long long i = 0; i < n - 1; i++)
        {
            for (long long j = i + 1; j < n; j++)
            {
                long long sum = a[i] + a[j];
                long long it1 = lower_bound(a.begin(), a.end(), a[n - 1] - sum + 1) - a.begin();
                it1 = max(it1, j + 1);
                long long it2 = upper_bound(a.begin(), a.end(), sum - 1) - a.begin();
                it2--;
                if (it2 >= it1)
                {
                    ans += it2 - it1 + 1;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}