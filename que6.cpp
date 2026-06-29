#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    else if (n == 2)
    {
        cout << 1 << " " << 2 << endl;
        return 0;
    }
    long long a = 0, b = 0;
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0 && __gcd(i, n / i) == 1)
        {
            a = i;
            b = n / i;
        }
    }
    cout << a << " " << b << endl;

    return 0;
}