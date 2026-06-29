#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (long long &it : a)
            cin >> it;
        vector<long long> mini(n);
        vector<long long> maxi(n);

        long long m = a[0];
        for (int i = 0; i < n; i++)
        {
            mini[i] = m;
            if (a[i] < m)
            {
                m = a[i];
            }
        }

        m = a[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            maxi[i] = m;
            if (a[i] > m)
            {
                m = a[i];
            }
        }

        string ans(n, '0');
        ans[0] = '1';
        ans[n - 1] = '1';
        for (int i = 1; i < n - 1; i++)
        {
            if (a[i] <= mini[i])
            {
                ans[i] = '1';
            }
            if (a[i] >= maxi[i])
            {
                ans[i] = '1';
            }
        }
        cout << ans << endl;
    }

    return 0;
}