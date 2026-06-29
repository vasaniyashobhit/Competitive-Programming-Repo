#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n, dist;
    cin >> n >> dist;
    vector<long long> d(n);
    for (long long &it : d)
        cin >> it;

    long long l = 0, r = 1;
    long long ans = 0;
    while (r < n)
    {
        while (d[r] - d[l] > dist)
        {
            l++;
        }
        ans += l;
        r++;
    }
    cout << ans << endl;

    return 0;
}