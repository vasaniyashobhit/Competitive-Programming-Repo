#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long a = 0, b = 0;
        long long minans = 10000000000;
        for (long long i = 1; i * i <= n; i++)
        {
            long long j = n - i;
            long long curr = (i * j / __gcd(i, j));
            if (curr < minans)
            {
                minans = curr;
                a = i;
                b = j;
            }
        }
        cout << a << " " << b << endl;
    }

    return 0;
}