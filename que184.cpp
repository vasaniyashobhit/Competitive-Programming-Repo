#include <iostream>
using namespace std;

long long next_prime(long long n)
{
    for (long long i = n;; i++)
    {
        bool isprime = true;
        for (long long j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                isprime = false;
                break;
            }
        }
        if (isprime)
            return i;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long d;
        cin >> d;

        long long p = next_prime(d + 1);
        long long q = next_prime(p + d);

        long long a = min(1LL * p * q, 1LL * p * p * p);
        cout << a << endl;
    }

    return 0;
}