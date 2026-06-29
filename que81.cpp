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
        long long n, q;
        cin >> n >> q;
        vector<long long> a(n);
        for (long long &it : a)
            cin >> it;
        vector<long long> k(q);
        for (long long &it : k)
            cin >> it;

        vector<long long> toth(n);
        toth[0] = a[0];
        for (long long i = 1; i < n; i++)
        {
            toth[i] = a[i] + toth[i - 1];
        }
        long long mini = a[0];
        vector<long long> minreq(n);
        for (long long i = 0; i < n; i++)
        {
            if (a[i] > mini)
            {
                mini = a[i];
            }
            minreq[i] = mini;
        }

        for (long long i = 0; i < q; i++)
        {
            auto it = upper_bound(minreq.begin(), minreq.end(), k[i]);
            long long ind = (it - minreq.begin());
            if (k[i] >= minreq[n - 1])
            {
                cout << toth[n - 1] << " ";
            }
            else if (k[i] < minreq[0])
            {
                cout << 0 << " ";
            }
            else
            {
                --ind;
                cout << toth[ind] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}