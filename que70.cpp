#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    vector<long long> b(m);
    for (long long &it : a)
        cin >> it;
    for (long long &it : b)
        cin >> it;
    long long sum = 0;
    for (long long i = 0; i < n; i++)
    {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        if (it != b.end())
        {
            auto it1 = upper_bound(b.begin(), b.end(), a[i]);
            sum += (it1 - it);
        }
    }
    cout << sum << endl;

    return 0;
}