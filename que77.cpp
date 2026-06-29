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
        long long n, m;
        cin >> n >> m;
        vector<long long> a(m);
        for (long long &it : a)
            cin >> it;
        sort(a.begin(), a.end());

        bool k = true;
        long long l = 0, r = m - 1;
        long long p = 2;
        while (n--)
        {
            if (p == 0)
            {
                p = 2;
                l++;
                r--;
            }
            if (p == 1)
                k = false;
            else if (p == 2)
                k = true;
            for (int i = 0; i < 6; i++)
            {
                if (k == true)
                {
                    cout << a[l] << " ";
                    k = false;
                }
                else
                {
                    cout << a[r] << " ";
                    k = true;
                }
            }
            cout << endl;
            p--;
        }
    }
}