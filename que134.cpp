#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long &it : a)
        cin >> it;
    sort(a.begin(), a.end());
    long long mid;
    if (n % 2 == 0)
    {
        mid = (a[n / 2] + a[(n / 2) - 1]) / 2;
    }
    else
    {
        mid = a[(n / 2)];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(mid - a[i]);
    cout << ans << endl;
}