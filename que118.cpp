#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &it : a)
            cin >> it;

        int srt = a[k - 1];
        set<int> st;
        for (auto it : a)
        {
            st.insert(it);
        }
        vector<int> res;
        for (auto it : st)
        {
            res.push_back(it);
        }
        if (res.size() < 2)
        {
            cout << "YES" << endl;
            continue;
        }
        // for (auto it : res)
        //     cout << it << " ";
        // cout << endl;
        auto it = upper_bound(res.begin(), res.end(), srt);
        int ind = it - res.begin();
        // cout << ind << endl;
        ind--;
        bool ans = true;
        int tim = 0;
        int currh = srt;
        while (ind < res.size() - 1)
        {
            int diff = res[ind + 1] - res[ind];
            // cout << tim << " " << diff << " " << currh << " ";
            if ((tim + diff - 1) >= currh)
            {
                ans = false;
                break;
            }
            else
            {
                ind++;
                currh = res[ind];
                tim += diff;
            }
        }
        // cout << endl;
        if (ans == true)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}