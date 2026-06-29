#include <iostream>
#include <string>
using namespace std;

long long mul(long long a, long long b, long long mod)
{
    long long ans = ((a % mod) * (b % mod)) % mod;
    return ans;
}

int main()
{
    string s;
    cin >> s;
    long long mod = 1e9 + 7;
    long long cnta = 0;
    long long n = s.size();

    long long ans = 1;
    long long count = 0;

    for (long long i = 0; i < n; i++)
    {
        // cout << ans << " ";
        if (s[i] == 'b')
        {
            if (count > 0)
                ans = mul(ans, count + 1, mod);
            count = 0;
        }
        else
        {
            if (s[i] == 'a')
                count++;
        }
    }
    if (count > 0)
        ans = mul(ans, count + 1, mod);
    if (ans == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        ans -= 1;
        cout << ans << endl;
    }
    return 0;
}