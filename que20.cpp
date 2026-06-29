#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<long long, long long>> v(n, {0, 0});
        for (auto &it : v)
        {
            cin >> it.first;
            cin >> it.second;
        }
        long long xlar = -1, xsecla = -1;
        long long xsm = __LONG_MAX__, xsecsm = __LONG_MAX__;

        long long ylar = -1, ysecla = -1;
        long long ysm = __LONG_MAX__, ysecsm = __LONG_MAX__;
        for (int i = 0; i < n; i++)
        {
            // for maximum and mininum in y axis;
            if (v[i].first >= xlar)
            {
                xsecla = xlar;
                xlar = v[i].first;
            }
            else if (v[i].first >= xsecla)
            {
                xsecla = v[i].first;
            }

            if (v[i].first <= xsm)
            {
                xsecsm = xsm;
                xsm = v[i].first;
            }
            else if (v[i].first <= xsecsm)
            {
                xsecsm = v[i].first;
            }

            // for y asix
            if (v[i].second >= ylar)
            {
                ysecla = ylar;
                ylar = v[i].second;
            }
            else if (v[i].second >= ysecla)
            {
                ysecla = v[i].second;
            }

            if (v[i].second <= ysm)
            {
                ysecsm = ysm;
                ysm = v[i].second;
            }
            else if (v[i].second <= ysecsm)
            {
                ysecsm = v[i].second;
            }
        }
        long long minans = __LONG_LONG_MAX__;
        for (int i = 0; i < n; i++)
        {
            if (v[i].first == xlar)
            {
                if (v[i].second == ysm)
                {
                    long long area = (xsecla - xsm + 1) * (ylar - ysm + 1);
                }
                else
                {
                    long long area = (xsecla - xsm + 1) * (ylar - ysm + 1);
                    minans = min(minans, area);
                }
            }
            else if (v[i].first == xsm)
            {
            }
        }
    }
    return 0;
}