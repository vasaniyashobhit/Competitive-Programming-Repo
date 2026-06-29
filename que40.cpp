#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

void precompute(vector<long long> &v)
{
    long long a, b, c;
    for (c = 1; c <= 1e9; c++)
    {
        a = sqrt(2 * c - 1);
        b = c - 1;
        if (a * a == b * b + c * c && (c >= a) && (c >= b))
        {
            v.push_back(c);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    vector<long long> v;
    precompute(v);
    while (t--)
    {
        long long n;
        cin >> n;
        auto itr = upper_bound(v.begin(), v.end(), n);
        long long ans = (itr - v.begin());
        cout << ans << endl;
    }

    return 0;
}