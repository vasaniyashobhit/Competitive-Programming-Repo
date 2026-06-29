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

        long long x = ((a[0] - n * (a[n - 1])) / (1 - n * n));
        long long y = ((n * (a[0]) - a[n - 1]) / (n * n - 1));
        // cout << x << " " << y << endl;

        if (x < 0 || y < 0)
        {
            cout << "NO" << endl;
            continue;
        }

        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            long long k = a[i];
            k -= (i + 1) * x;
            k -= (n - i) * y;
            if (k != 0)
            {
                ans = false;
                break;
            }
        }

        if (ans == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}