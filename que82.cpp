#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &it : a)
            cin >> it;
        sort(a.begin(), a.end());

        vector<int> ans(n + 2, 0);
        map<int, int> mp;
        for (int it : a)
        {
            if (mp.find(it) == mp.end())
                mp[it] = 1;
            else
                mp[it]++;
        }
        int i = 0;
        while (mp.find(i) != mp.end())
        {
            ans[i]++;
            ans[n - mp[i] + 1]--;
            i++;
        }
        ans[i]++;
        ans[n + 1];
        for (int j = 1; j <= n; j++)
            ans[j] += ans[j - 1];
        for (int j = n; j >= 0; j--)
            cout << ans[j] << " ";
        cout << endl;
    }

    return 0;
}