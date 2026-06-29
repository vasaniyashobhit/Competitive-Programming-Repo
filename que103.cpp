#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long &it : a)
            cin >> it;

        long long ans = min(a[0] + a[1], a[0] + a[0]);
        cout << ans << endl;
    }

    return 0;
}