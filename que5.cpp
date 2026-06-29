#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<long long> a(1000001, 1);

void sieve(map<long long, long long> &hash)
{
    long long maxn = 1000000;
    a[0] = a[1] = 0;
    for (long long i = 2; i * i <= maxn; i++)
    {
        if (a[i])
        {
            for (long long j = i * i; j <= maxn; j = j + i)
            {
                a[j] = 0;
            }
        }
    }

    for (long long i = 2; i <= maxn; i++)
    {
        if (a[i])
        {
            hash[i * i] = 1;
        }
    }
}

int main()
{
    map<long long, long long> hash;
    sieve(hash);
    long long n;
    cin >> n;
    vector<long long> x(n, 0);
    for (long long &it : x)
        cin >> it;
    for (long long i = 0; i < n; i++)
    {
        if (hash.find(x[i]) == hash.end())
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}