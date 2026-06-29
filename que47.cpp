#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool check(vector<long long> a, long long mid)
{
    long long n = a.size();
    bool k = true;
    long long j = n - 1;
    for (long long i = mid - 1; i >= 0; i--)
    {
        if (a[i] >= a[j] || a[i] >= a[j - 1])
        {
            k = false;
            break;
        }
        j--;
    }
    return k;
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long &it : a)
        cin >> it;
    sort(a.begin(), a.end());

    long long l = 0, r = n;
    long long m;
    if (n % 2 == 0)
    {
        m = n / 2 - 1;
    }
    else
    {
        m = n / 2;
    }
    long long ans = -1;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        if (check(a, mid) && mid <= m)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    long long i = ans - 1, j = n - 1;
    while (i >= 0)
    {
        cout << a[j] << " ";
        cout << a[i] << " ";
        i--, j--;
    }
    while (j >= ans)
    {
        cout << a[j] << " ";
        j--;
    }
    cout << endl;

    return 0;
}