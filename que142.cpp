#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<pair<int, int>> a(n, {0, 0}); // deadline,time
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].second;
        cin >> a[i].first;
    }
    sort(a.begin(), a.end());
    long long sum = 0;
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        sum += a[i].second;
        if (sum > a[i].first)
        {
            ans = false;
            break;
        }
    }
    if (ans == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}