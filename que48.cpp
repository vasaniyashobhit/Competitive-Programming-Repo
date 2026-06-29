#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long> a, vector<long long> pref, long long op, long long k)
{
    long long n = pref.size();
    long long req = pref[n - 1] - k;
    bool ch = false;
    // cout << req << " ";
    for (long long op2 = op; op2 >= 0; op2--)
    {
        long long op1 = op - op2;
        long long diff;
        if (n == 1)
        {
            diff = op1;
        }
        else if (op2 > n)
        {
            continue;
        }
        else if (op2 == n)
        {
            diff = pref[n - 1] - (a[0] * op2) + (op1 * op2);
        }
        else
        {
            diff = op1 + pref[n - 1] - pref[n - 1 - op2] - (a[0] * op2) + (op1 * op2);
        }
        // cout << diff << " ";
        if (diff >= req)
        {
            // cout << op << " " << op2 << " " << diff << endl;
            ch = true;
            break;
        }
    }
    return ch;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        int sum = 0;
        vector<long long> a(n);
        for (long long &it : a)
        {
            cin >> it;
            sum += it;
        }
        sort(a.begin(), a.end());
        vector<long long> pref(n);
        pref[0] = a[0];
        for (long long i = 1; i < n; i++)
        {
            pref[i] = a[i] + pref[i - 1];
        }

        long long l = 0, r = sum - k + 1;
        long long ans = 0;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            if (check(a, pref, mid, k))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}