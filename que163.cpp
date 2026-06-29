#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> fact;
        pair<long long, long long> p;
        for (long long i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                fact.push_back(i);
                fact.push_back(n / i);
            }
        }
        long long minlc = 1e9 + 1;
        for (long long it : fact)
        {
            long long b = n - it;
            long long lc = (it * b) / __gcd(it, b);
            if (it != n && lc < minlc)
            {
                minlc = lc;
                p.first = it;
                p.second = b;
            }
        }
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}