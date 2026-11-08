#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll getFactorial(ll a, ll cnt)
{
    if (cnt < 3)
        return 0;
    return (cnt * (cnt - 1) * (cnt - 2));
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &it : a)
        cin >> it;
    sort(a.begin(), a.end());

    // for(auto it:a) cout<<it<<" ";

    ll m = -1;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        m = max(a[i], m);
        if (mp.find(a[i]) == mp.end())
            mp[a[i]] = 1;
        else
            mp[a[i]]++;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {

        if (i != 0 && a[i] == a[i - 1])
            continue;

        ans += getFactorial(a[i], mp[a[i]]);

        for (ll b = 2; b * b * a[i] <= m; b++)
        {
            ll cnt = 1;
            cnt *= (mp.find(a[i]) != mp.end()) ? mp[a[i]] : 0;
            cnt *= (mp.find(a[i] * b) != mp.end()) ? mp[a[i] * b] : 0;
            cnt *= (mp.find(a[i] * b * b) != mp.end()) ? mp[a[i] * b * b] : 0;
            ans += cnt;
        }
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