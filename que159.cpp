#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, q;
        cin >> n >> k >> q;
        vector<long long> a(n);
        for (long long &it : a)
            cin >> it;

        long long l = 0, r = 0, ans = 0;
        while (r < n)
        {
            if (a[r] <= q)
            {
                ans += max(0ll, r - l + 2 - k);
                r++;
            }
            else
            {
                while (a[r] > q)
                {
                    r++;
                    if (r == n)
                        break;
                }
                l = r;
            }
        }
        cout << ans << endl;
    }

    return 0;
}