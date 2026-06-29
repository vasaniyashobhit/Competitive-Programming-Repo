#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    long long n, s;
    cin >> n >> s;
    vector<long long> a(n);
    for (long long &it : a)
        cin >> it;
    long long l = 0, r = 0;
    long long ans = 0;
    long long sum = 0;
    while (r < n)
    {
        sum += a[r];
        while (sum > s)
        {
            sum -= a[l];
            l++;
        }
        long long len = (r - l + 1);
        ans += (len * (len + 1)) / 2;
        r++;
    }
    cout << ans << endl;

    return 0;
}