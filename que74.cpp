#include <iostream>
#include <vector>
using namespace std;

bool check(long long mid, vector<long long> a, long long k, vector<long long> h)
{
    long long n = a.size();
    long long sum = 0;
    long long l = 0, r = 0;
    while (l < n && r < n)
    {
        sum += a[r];
        while (sum > k)
        {
            sum -= a[l];
            l++;
        }
        long long len = r - l + 1;
        if (len >= mid)
            return true;

        if ((r < n - 1) && (h[r] % h[r + 1] != 0))
        {
            sum = 0;
            l = r + 1;
        }
        r++;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        vector<long long> h(n);
        for (long long &it : a)
            cin >> it;
        for (long long &it : h)
            cin >> it;

        long long ans = 0;
        long long l = 1, r = n;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            if (check(mid, a, k, h))
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
    }

    return 0;
}