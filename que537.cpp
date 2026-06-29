#include <bits/stdc++.h>
using namespace std;

vector<long long> fact;
vector<long long> invFact;

long long power(long long base, long long exp, long long mod)
{
    long long res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// Function to calculate modular inverse using Fermat's Little Theorem
long long modInverse(long long n, long long mod)
{
    return power(n, mod - 2, mod);
}

// Precompute factorials and inverse factorials up to maxN
void precompute(int maxN, long long mod)
{
    fact.resize(maxN + 1);
    invFact.resize(maxN + 1);

    fact[0] = 1;
    invFact[0] = 1;

    for (int i = 1; i <= maxN; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    invFact[maxN] = modInverse(fact[maxN], mod);
    for (int i = maxN - 1; i >= 1; i--)
    {
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
    }
}

// Function to calculate nCr % mod in O(1) time
long long nCr(int n, int r, long long mod)
{
    if (r < 0 || r > n)
        return 0;
    return fact[n] * invFact[r] % mod * invFact[n - r] % mod;
}

int main()
{

    long long mod = 998244353;

    long long n;
    cin >> n;
    precompute(n, mod);
    vector<long long> a(n);
    for (long long &it : a)
        cin >> it;

    long long ans = nCr(n / 3, n / 6, mod);
   

    for (int i = 0; i < n; i += 3)
    {
        if (a[i] == a[i + 1] && a[i + 1] == a[i + 2]){
            ans = (ans*3)%mod;
        }
        else if (a[i] != a[i + 1] && a[i] != a[i + 2] && a[i + 1] != a[i + 2])
            continue;
        else
        {
            if (a[i] == a[i + 1])
            {
                if (a[i] > a[i + 2])
                    continue;
                else
                    ans = (ans * 2) % mod;
            }
            else if (a[i] == a[i + 2])
            {
                if (a[i] > a[i + 1])
                    continue;
                else
                    ans = (ans * 2) % mod;
            }
            else
            {
                if (a[i] < a[i + 1])
                    continue;
                else
                    ans = (ans * 2) % mod;
            }
        }
    }
    cout << ans << endl;

    return 0;
}