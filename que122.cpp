#include <iostream>
#include <vector>
using namespace std;

long long binexp(long long a, long long b, long long mod)
{
    long long ans = a;
    long long res = 1;
    while (b > 1)
    {
        if (b % 2 == 0)
        {
            ans = ((ans % mod) * (ans % mod)) % mod;
            b /= 2;
        }
        else
        {
            res = ((res % mod) * (ans % mod)) % mod;
            b--;
        }
    }
    ans = ((res % mod) * (ans % mod)) % mod;
    return ans;
}

int main()
{
    long long mod = 1e9 + 7;
    long long n;
    cin >> n;

    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<long long> fact(n + 1, 1);
    // vector<long long> ifact(n + 1);
    fact[0] = fact[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = (i * (fact[i - 1])) % mod;
    }
    // ifact[n] = binexp(fact[n], mod - 2, mod);
    // for (int i = n - 1; i > 0; i--)
    // {
    //     ifact[i] = (((ifact[i + 1]) % mod) * ((i + 1) % mod)) % mod;
    // }

    long long ans = 0;
    long long sign = 1;
    for (int i = 2; i <= n; i++)
    {
        if (sign == 1)
            ans = (ans + (fact[n] * (binexp(fact[i], mod - 2, mod) % mod))) % mod;
        else
            ans = (ans - ((fact[n] * binexp(fact[i], mod - 2, mod) % mod)) + mod) % mod;
        sign *= -1;
    }

    cout << ans << endl;

    return 0;
}