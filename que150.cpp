#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, c;
        cin >> n >> c;
        vector<long long> w(n);
        for (long long &it : w)
            cin >> it;

        sort(w.begin(), w.end());

        long long ans = 0;
        long long ind = n - 1;
        long long i = 1;
        while (ind >= 0)
        {
            if ((w[ind] * i) > c)
            {
                ans++;
            }
            else
            {
                i *= 2;
            }
            ind--;
        }
        // cout << endl;
        cout << ans << endl;
    }

    return 0;
}