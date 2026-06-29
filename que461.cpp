#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long m = 1e9 + 7;

    vector<long long> dp1(4, 0);
    vector<long long> dp2(4, 0);
    dp1[0] = dp1[1] = dp1[2] = 1;
    dp1[3] = 0;

    for (long long i = 2; i <= n; i++)
    {
        long long sum = (dp1[0] + dp1[1] + dp1[2] + dp1[3]) % m;

        for (long long j = 0; j < 4; j++)
        {
            dp2[j] = (sum - dp1[j] + m) % m;
        }
        swap(dp1, dp2);
    }
    cout << dp1[3] << endl;

    return 0;
}