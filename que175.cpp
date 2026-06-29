#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        vector<long long> b(n);
        for (long long &it : a)
            cin >> it;
        for (long long &it : b)
            cin >> it;
        long long sum = 0, maxi = b[0], ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == k)
                break;
            sum += a[i];
            maxi = max(maxi, b[i]);
            ans = max(ans, sum + (k - i - 1) * maxi);
            // cout << i << "-" << ans << " ";
        }
        // cout << endl;
        cout << ans << endl;
    }

    return 0;
}