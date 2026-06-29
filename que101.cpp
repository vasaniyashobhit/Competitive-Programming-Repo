#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
using namespace std;

long long gcdd(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    return gcdd(b, a % b);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        long long n;
        cin >> n;
        vector<long long> b(n);
        for (long long &it : b)
            cin >> it;

        long long ans = 1;
        for (long long i = n - 2; i >= 0; i--)
        {
            if (b[i + 1] % b[i] != 0)
            {
                long long k = b[i] / gcdd(b[i + 1], b[i]);
                if (ans % k != 0)
                {
                    ans = (k * ans) / gcdd(k, ans);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}

// 42 42 14 84 28 73080 255780