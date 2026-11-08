#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &it : a)
        cin >> it;
    sort(a.begin(), a.end());

    ll m = a[n - 1];
    if (a[0] != 0)
    {
        cout << (m * n) << endl;
        return;
    }

    if (m == 0)
    {
        cout << n << endl;
        return;
    }
    else if (m == 1)
    {
        ll ans = n + 2 * (n - 1);
        cout << ans << endl;
        return;
    }

    ll f = -1;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == f + 1)
            f++;
    }
    f++;

    ll ind = f - 1;
    ll ans = m * (n);

    if (f < m)
    {
        ans += (f * (f + 1)) / 2;
        ans += f * (n - f - 1);
    }
    else
    {
        ans += ((f - 1) * (f - 2)) / 2;
        ans += f * (n - (f - 2) - 1);
    }

    cout << ans << endl;

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