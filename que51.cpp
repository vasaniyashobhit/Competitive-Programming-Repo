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
        long long n, k;
        cin >> n >> k;
        vector<long long> z(65, 0);
        vector<long long> a(n, 0);
        for (long long &it : a)
            cin >> it;
        long long count = 0;

        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < 64; j++)
            {
                if ((a[i] & 1ll << j) == 0)
                {
                    z[j]++;
                }
                else
                {
                    count++;
                }
            }
        }
        // cout << count << endl;
        //    for (auto it : z)
        //        cout << it << " ";
        //    cout << endl;

        for (long long i = 0; i <= 63; i++)
        {
            long long cann = 1ll << i;
            long long tot = z[i] * cann;
            if (k >= tot)
            {
                count += z[i];
                k -= tot;
            }
            else
            {
                // cout << i << endl;
                count += k / cann;
                break;
            }
        }

        cout << count << endl;
    }

    return 0;
}