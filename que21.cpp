#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<pair<long long, long long>> v(n, {0, 0});
        multiset<long long> xi;
        multiset<long long> yi;
        for (auto &it : v)
        {
            cin >> it.first;
            cin >> it.second;
            xi.insert(it.first);
            yi.insert(it.second);
        }
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }

        long long minans = __LONG_LONG_MAX__;
        for (long long i = 0; i < n; i++)
        {
            long long area = __LONG_LONG_MAX__;
            auto it1 = xi.begin();
            auto it2 = --xi.end();
            auto it3 = yi.begin();
            auto it4 = --yi.end();
            if (v[i].first == *(it1))
            {
                it1++;
            }
            else if (v[i].first == *(it2))
            {
                it2--;
            }
            if (v[i].second == *(it3))
            {
                it3++;
            }
            else if (v[i].second == *(it4))
            {
                it4--;
            }
            area = (*(it2) - *(it1) + 1) * (*(it4) - *(it3) + 1);
            if (area == n - 1)
            {
                long long area1 = (*(it2) - *(it1) + 2) * (*(it4) - *(it3) + 1);
                long long area2 = (*(it2) - *(it1) + 1) * (*(it4) - *(it3) + 2);
                area = min(area1, area2);
            }
            minans = min(area, minans);
        }
        cout << minans << endl;
    }
    return 0;
}