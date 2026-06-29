#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, d;
        cin >> n >> k >> d;
        vector<long long> a(n);
        for (long long &it : a)
            cin >> it;

        map<long long, long long> mp;
        for (long long i = 0; i < d; i++)
        {
            if (mp.find(a[i]) == mp.end())
            {
                mp[a[i]] = 1;
            }
            else
                mp[a[i]]++;
        }
        long long ans = mp.size();
        for (long long i = d; i < n; i++)
        {
            if (mp.find(a[i]) == mp.end())
            {
                mp[a[i]] = 1;
            }
            else
                mp[a[i]]++;

            mp[a[i - d]]--;
            if (mp[a[i - d]] == 0)
                mp.erase(a[i - d]);
            long long siz = mp.size();
            ans = min(ans, siz);
        }
        cout << ans << endl;
    }

    return 0;
}