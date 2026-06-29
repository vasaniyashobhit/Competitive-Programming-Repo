#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n, t;
    cin >> n >> t;
    vector<long long> a(n);
    for (long long &it : a)
        cin >> it;

    long long ans = 0, sum = 0;
    long long l = 0, r = 0;
    while (l < n && r < n)
    {
        sum += a[r];
        while (sum > t)
        {
            sum -= a[l];
            l++;
        }
        ans = max(ans, r - l + 1);
        r++;
    }
    cout << ans << endl;

    return 0;
}