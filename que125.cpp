#include <iostream>
#include <vector>
using namespace std;

long long bine(long long a, long long b)
{
    long long ans = a;
    long long res = 1;
    while (b > 1)
    {
        if (b % 2 == 0)
        {
            ans *= ans;
            b /= 2;
        }
        else
        {
            res *= ans;
            b--;
        }
    }
    ans *= res;
    return ans;
}

int main()
{
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m, 0));
    for (auto &it : a)
    {
        for (auto &itt : it)
            cin >> itt;
    }

    long long ans = n * m;
    for (int i = 0; i < n; i++)
    {
        long long one = 0;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1)
                one++;
        }
        long long zr = m - one;
        if (one >= 2)
            ans += bine(2, one) - 1 - one;
        if (zr >= 2)
            ans += bine(2, zr) - 1 - zr;
    }

    for (int j = 0; j < m; j++)
    {
        long long one = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] == 1)
                one++;
        }
        long long zr = n - one;
        if (one >= 2)
            ans += bine(2, one) - 1 - one;
        if (zr >= 2)
            ans += bine(2, zr) - 1 - zr;
    }

    cout << ans << endl;
    return 0;
}