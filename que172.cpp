#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long &it : a)
            cin >> it;
        long long pos = 0, ans = 0, mon = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] >= 0)
                pos += a[i];
            else
            {
                if (pos >= abs(a[i]))
                    pos -= abs(a[i]);
                else
                {
                    a[i] += pos;
                    ans += abs(a[i]);
                    mon += abs(a[i]);
                    pos = 0;
                }
            }
        }
        if (mon < pos)
            ans += pos - mon;

        cout << ans << endl;
    }

    return 0;
}