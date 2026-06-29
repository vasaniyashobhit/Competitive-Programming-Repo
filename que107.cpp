#include <iostream>
#include <vector>
#include <bits/stdc++.h>
// #include<math.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (long long &it : a)
            cin >> it;

        long long l = 1, r = n - 2;
        long long ans = abs(a[0] - a[n - 1]);
        while (l < r)
            ans = __gcd(ans, abs(a[l++] - a[r--]));
        cout << ans << endl;
    }

    return 0;
}