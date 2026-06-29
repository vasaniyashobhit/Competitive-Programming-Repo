#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    long long mod = 1e9 + 7;
    vector<string> a(n);
    for (auto &it : a)
        cin >> it;

    long long ans = 1;
    for (int j = 0; j < m; j++)
    {
        map<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[a[i][j]] = 1;
        }
        long long si = mp.size();
        ans = ((ans % mod) * (si % mod)) % mod;
        mp.clear();
    }
    cout << ans << endl;
    return 0;
}