#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, d;
    cin >> n >> d;
    vector<long long> p(n);
    for (long long &it : p)
        cin >> it;
    sort(p.begin(), p.end());
    long long cnt = n, ans = 0;
    d++;
    for (int i = n - 1; i >= 0; i--)
    {
        long long req = (d % p[i] == 0) ? d / p[i] : (d / p[i]) + 1;
        // cout << "h1" << " ";
        if (req <= cnt)
        {
            cnt -= req;
            ans++;
        }
        else
            break;
    }
    cout << ans << endl;
}