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
        long long n, l, r, k;
        cin >> n >> l >> r >> k;
        if (n % 2 == 1)
        {
            cout << l << endl;
        }
        else
        {
            if (n <= 2)
                cout << -1 << endl;
            else
            {
                long long re = 0;
                for (long long i = 0; i < 64; i++)
                {
                    if ((l & (1ll << i)))
                    {
                        // cout << " w43r5";
                        re = i;
                    }
                }

                if ((1ll << (re + 1)) > r)
                {
                    cout << -1 << endl;
                }
                else
                {
                    if (k < n - 1)
                    {
                        // cout << "he" << endl;
                        cout << l << endl;
                    }
                    else
                    {
                        // cout << "j1" << endl;
                        // cout << re << endl;
                        long long ans = 1ll << (re + 1);
                        cout << ans << endl;
                    }
                }
            }
        }
    }

    return 0;
}