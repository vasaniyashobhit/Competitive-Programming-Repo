#include <iostream>
#include <vector>
using namespace std;

bool check(vector<long long> a, long long count)
{
    long long n = a.size();
    bool k = true;
    for (int i = 0; i < n - 2; i++)
    {
        if (a[i] < count)
        {
            int req = count - a[i];
            if (req % 2 != 0)
                req++;
            if ((req + req / 2) > a[i + 2])
            {
                k = false;
                break;
            }
            else
            {
                a[i] += req;
                a[i + 1] += req / 2;
                a[i + 2] -= (req + req / 2);
            }
        }
    }
    if (a[n - 2] < count || a[n - 1] < count)
    {
        k = false;
    }

    return k;
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> v(n);
        long long max = 1;
        for (long long &it : v)
        {
            cin >> it;
            if (it > max)
            {
                max = it;
            }
        }

        long long l = 1, r = max;
        long long ans = 1;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            if (check(v, mid))
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