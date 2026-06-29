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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &it : v)
            cin >> it;

        pair<int, int> ans = {1, n};
        int l = 0, r = n - 1;
        pair<int, int> res = {-1, -1};
        while (l < r)
        {
            if (v[l] != ans.first && v[l] != ans.second && v[r] != ans.first && v[r] != ans.second)
            {
                res.first = l + 1;
                res.second = r + 1;
                break;
            }

            while (v[l] == ans.first || v[l] == ans.second)
            {
                if (v[l] == ans.first)
                {
                    ans.first++;
                    l++;
                }
                if (v[l] == ans.second)
                {
                    ans.second--;
                    l++;
                }
            }

            while (v[r] == ans.first || v[r] == ans.second)
            {
                if (v[r] == ans.first)
                {
                    ans.first++;
                    r--;
                }
                if (v[r] == ans.second)
                {
                    ans.second--;
                    r--;
                }
            }
        }
        if (res.first == -1 || res.second == -1 || l >= r)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << res.first << " " << res.second << endl;
        }
    }

    return 0;
}