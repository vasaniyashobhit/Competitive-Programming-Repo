#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, k;
        cin >> n >> m >> k;
        if (k % n == 0)
        {
            k = k / n;
        }
        else
        {
            k = k / n;
            k++;
        }

        long long l = 1, r = m;
        long long ans;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            long long sets = k / mid;
            long long gap = m - k;
            if (k % mid != 0)
                sets++;

            if (sets - 1 <= gap)
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