#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    if(__gcd(n,a)==1 && __gcd(m,b)==1 && __gcd(n,m)<=2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

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