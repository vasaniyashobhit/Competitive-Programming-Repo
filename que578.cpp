#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &it : a)
        cin >> it;
    map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[a[i]] = 1;


    bool ans = false;
   
    for (int i = 0; i < n; i++)
    {
        if (mp.find((a[i] - k)) != mp.end())
        {
            ans = true;
            break;
        }
    }
    if (ans == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return;
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}