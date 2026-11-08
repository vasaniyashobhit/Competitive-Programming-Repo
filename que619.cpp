#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int n;
    cin >> n;
    n *= 2;
    vector<int> a(n);
    for (int &it : a)
        cin >> it;
    sort(a.begin(), a.end());
    a.push_back(-1);

    int ans = 0;
    int totcnt = 0;
    int len = 1;
    bool k = false;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != a[i - 1])
        {
            if (len % 2 == 0)
            {
                if ((len / 2) % 2 == 0)
                {
                    //cout << i << " ";
                    totcnt++;
                }
                else
                    ans += 2;
            }
            else
            {
                ans++;
                k = true;
            }
            len = 1;
        }
        else
        {
            len++;
        }
    }
    //cout << endl;
    //cout << ans << "-" << totcnt << endl;
    if (totcnt == 1)
    {
        if (k == true)
            ans += 2 * totcnt;
    }
    else if (totcnt >= 2)
    {
        if (totcnt % 2 == 0)
            ans += 2 * totcnt;
        else if (k == true)
            ans += 2 * totcnt;
        else{
            ans += 2*(totcnt-1);
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