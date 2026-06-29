#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, x;
        cin >> n >> x;
        vector<long long> a(n, 0);
        for (long long &it : a)
            cin >> it;
        long long sum = 0;
        long long ans1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % x == 0)
                ans1 += a[i] / x;
            else
                ans1 += ((a[i] / x) + 1);
            sum += a[i];
        }
        long long ans2;
        if (sum % x == 0)
            ans2 = sum / x;
        else
            ans2 = ((sum / x) + 1);
        cout << ans2 << " " << ans1 << endl;
    }

    return 0;
}