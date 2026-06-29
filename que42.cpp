#include <iostream>
#include <vector>
using namespace std;

long long ask(long long b)
{
    cout << "? " << b << " ";
    for (int i = 1; i <= b; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    long long sum;
    cin >> sum;
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (auto &it : a)
            cin >> it;

        vector<long long> pref(n, 0);
        pref[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            pref[i] = a[i] + pref[i - 1];
        }

        long long l = 1, r = n;
        long long ans = -1;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            long long sum = ask(mid);

            if (pref[mid - 1] == sum)
            {
                l = mid + 1;
            }
            else
            {
                ans = mid;
                r = mid - 1;
            }
        }
        cout << "! " << ans << endl;
    }

    return 0;
}