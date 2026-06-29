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
        long long cnt = (n / 2) + 1;
        long long i = n * k - cnt;
        vector<long long> a(n * k, 0);
        for (auto &it : a)
            cin >> it;
        long long ans = 0;
        while (k--)
        {
            ans += a[i];
            i -= cnt;
        }
        cout << ans << endl;
    }

    return 0;
}