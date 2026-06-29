#include <iostream>
#include <vector>
using namespace std;

long long ncr(long long nn, long long rr, vector<long long> fact)
{
    long long ans = 1;
    for (long long i = nn; i > nn - rr; i--)
    {
        ans *= i;
    }
    ans /= fact[rr];
    return ans;
}

long long De(long long nn, vector<long long> fact)
{
    long long sign = 1;
    long long d = 0;
    for (int i = 2; i <= nn; i++)
    {
        if (sign == 1)
            d += fact[nn] / fact[i];
        else
            d -= fact[nn] / fact[i];
        sign *= -1;
    }
    return d;
}

int main()
{
    long long n, k;
    cin >> n >> k;
    long long ans = 1;

    vector<long long> fact(6, 1);
    fact[0] = fact[1] = 1;
    for (long long i = 2; i <= 5; i++)
        fact[i] = i * (fact[i - 1]);

    for (long long i = k; i >= 2; i--)
    {
        ans += ncr(n, i, fact) * De(i, fact);
    }

    cout << ans << endl;

    return 0;
}