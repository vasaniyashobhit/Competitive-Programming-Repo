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
        cin >> it;
    sort(a.begin(), a.end());

    if (a[0] != 1)
    {
        cout << 1 << endl;
        return 0;
    }
    pair<long long, long long> prev = {0, 0};
    long long ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > prev.second + 1)
        {
            ans = prev.second + 1;
            break;
        }
        prev.second += a[i];
    }
    if (ans == -1)
        cout << (prev.second + 1) << endl;
    else
        cout << ans << endl;
    return 0;
}