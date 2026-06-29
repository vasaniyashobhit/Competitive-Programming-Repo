#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        long long k, a, b, x, y;
        cin >> k >> a >> b >> x >> y;
        int ans = 0;

        if (k >= a && k >= b)
        {
            if (x < y)
            {
                int cnt = k - a;
                cnt = cnt / x;
                ans = cnt;
                k -= x * ans;
                if (k >= x && k >= a)
                {
                    ans++;
                    k -= x;
                }

                if (k >= b && k >= y)
                {
                    cnt = k - b;
                    cnt = cnt / y;
                    ans += cnt;
                    k -= cnt * y;
                    if (k >= b && k >= y)
                    {
                        ans++;
                    }
                }
            }
            else
            {
                int cnt = k - b;
                cnt = cnt / y;
                ans = cnt;
                k -= y * ans;
                if (k >= y && k >= b)
                {
                    ans++;
                    k -= y;
                }

                if (k >= a && k >= x)
                {
                    cnt = k - a;
                    cnt = cnt / x;
                    ans += cnt;
                    k -= cnt * x;
                    if (k >= a && k >= x)
                    {
                        ans++;
                    }
                }
            }
        }
        else if (k >= a)
        {
            int cnt = k - a;
            cnt = cnt / x;
            ans = cnt;
            k -= x * ans;
            if (k >= x && k >= a)
            {
                ans++;
                k -= x;
            }
        }
        else if (k >= b)
        {
            int cnt = k - b;
            cnt = cnt / y;
            ans = cnt;
            k -= y * ans;
            if (k >= y && k >= b)
            {
                ans++;
                k -= y;
            }
        }

        cout << ans << endl;
    }

    return 0;
}