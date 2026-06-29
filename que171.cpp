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
        vector<long long> a(n);
        for (long long &it : a)
            cin >> it;
        pair<long long, long long> p = {a[0], -1}; // {mini,maxi}
        long long ans = 0;
        x *= 2;
        for (int i = 1; i < n; i++)
        {
            if (p.second == -1)
            {
                if (abs(p.first - a[i]) > x)
                {
                    ans++;
                    p.first = a[i];
                }
                else
                {
                    if (a[i] <= p.first)
                    {
                        p.second = p.first;
                        p.first = a[i];
                    }
                    else
                        p.second = a[i];
                }
            }
            else
            {
                if (a[i] > p.second)
                {
                    if (a[i] > p.first + x)
                    {
                        ans++;
                        p.first = a[i];
                        p.second = -1;
                    }
                    else
                        p.second = a[i];
                }
                else if (a[i] < p.first)
                {
                    if (a[i] < p.second - x)
                    {
                        ans++;
                        p.first = a[i];
                        p.second = -1;
                    }
                    else
                        p.first = a[i];
                }
            }
        }
        cout << ans << endl;
    }
}