#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &it : a)
    {
        cin >> it;
        it = abs(it);
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto itr = upper_bound(a.begin(), a.end(), 2 * (a[i]));
        itr--;
        ans += itr - a.begin() - i;
    }
    cout << ans << endl;

    return 0;
}