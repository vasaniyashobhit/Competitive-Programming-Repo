#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <map>
using namespace std;

int main()
{
    long long n, k, m;
    cin >> n >> k >> m;
    vector<long long> a(n);
    for (long long &it : a)
        cin >> it;
    map<long long, long long> mp;
    bool ans = false;
    long long val;
    for (int i = 0; i < n; i++)
    {
        long long it = a[i] % m;
        if (mp.find(it) == mp.end())
        {
            mp[it] = 1;
        }
        else
            mp[it]++;

        if (mp[it] >= k)
        {
            val = it;
            ans = true;
            break;
        }
    }
    if (ans == false)
        cout << "No" << endl;
    else
    {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % m == val)
            {
                cout << a[i] << " ";
                k--;
            }
            if (k == 0)
                break;
        }
    }

    return 0;
}