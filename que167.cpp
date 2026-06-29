#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        map<pair<int, int>, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            cin >> a[i].second;
            mp[{a[i].first, a[i].second}] = i + 1;
        }
        sort(a.begin(), a.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
        if (a.first != b.first) {
            return a.first < b.first; 
        }
        else {
            return a.second > b.second; 
        } });

        int cnt = 1;
        int ind = mp[{a[0].first, a[0].second}];
        vector<int> ans = {ind};
        int prev = a[0].first;
        for (int i = 1; i < n; i++)
        {
            if (a[i].first != prev)
            {
                cnt++;
                ind = mp[{a[i].first, a[i].second}];
                ans.push_back(ind);
                prev = a[i].first;
            }
        }
        cout << cnt << endl;
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }

    return 0;
}