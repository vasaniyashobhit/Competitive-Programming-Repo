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
        int n;
        cin >> n;
        vector<long long> a(n);
        for (long long &it : a)
            cin >> it;
        map<long long, long long> mp;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(a[i]) == mp.end())
            {
                mp[a[i]] = 1;
            }
            else
                mp[a[i]]++;
        }

        vector<int> hash(n + 1, 0);
        for (auto it : mp)
        {
            if (it.first <= n)
            {
                long long k = it.first;
                long long cnt = it.second;
                for (long long j = k; j <= n; j += k)
                {
                    hash[j] += cnt;
                }
            }
        }

        long long maxi = 0;
        for (int i = 1; i <= n; i++)
        {
            if (hash[i] > maxi)
                maxi = hash[i];
        }
        cout << maxi << endl;
    }

    return 0;
}