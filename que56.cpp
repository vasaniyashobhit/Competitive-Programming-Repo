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
                ans = cnt + 1;
                k -= x * (cnt + 1);

                if (k >= b)
                {
                    cnt = k - b;
                    cnt = cnt / y;
                    ans += cnt + 1;
                }
            }
            else
            {
                int cnt = k - b;
                cnt = cnt / y;
                ans = cnt + 1;
                k -= y * (cnt + 1);

                if (k >= a)
                {
                    cnt = k - a;
                    cnt = cnt / x;
                    ans += cnt + 1;
                }
            }
        }
        else if (k >= a)
        {
            int cnt = k - a;
            cnt = cnt / x;
            ans = cnt + 1;
            k -= x * (cnt + 1);
        }
        else if (k >= b)
        {
            int cnt = k - b;
            cnt = cnt / y;
            ans = cnt + 1;
            k -= y * (cnt + 1);
        }

        cout << ans << endl;
    }

    return 0;
}