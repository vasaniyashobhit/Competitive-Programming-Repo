#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, x, y;
        cin >> a >> b >> x >> y;
        if (a > b)
        {
            if (a > b + 1)
            {
                cout << -1 << endl;
                continue;
            }
            else if (a == b + 1)
            {
                if (a % 2 != 0)
                {
                    cout << y << endl;
                    continue;
                }
                else
                {
                    cout << -1 << endl;
                    continue;
                }
            }
        }
        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }
        // diff

        if (x <= y)
        {
            cout << x * (b - a) << endl;
        }
        else
        {
            long long ans = 0;
            long long inc = (b - a);
            if (inc % 2 == 0)
            {
                ans += x * ((inc) / 2);
                ans += y * ((inc) / 2);
            }
            else
            {
                if (a % 2 == 0)
                {
                    ans += y * ((inc / 2) + 1);
                    ans += x * (inc / 2);
                }
                else
                {
                    ans += x * ((inc / 2) + 1);
                    ans += y * (inc / 2);
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}