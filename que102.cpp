#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
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
        vector<int> b(n);
        int i = 0;
        for (auto &it : a)
        {
            cin >> it;
            b[i++] = it;
        }
        if (k == 1)
        {
            cout << "YES" << endl;
            continue;
        }
        sort(b.begin(), b.end());
        int sec = b[k - 2];
        int it = upper_bound(b.begin(), b.end(), sec) - b.begin();
        int cnt = it - k + 1;
        vector<int> fin;
        for (int i = 0; i < n; i++)
        {
            if (a[i] <= sec)
                fin.push_back(a[i]);
        }

        int l = 0, r = fin.size() - 1;
        bool ans = true;
        // cout << sec << endl;
        while (l <= r)
        {
            // cout << "hello" << " ";
            if (fin[l] != fin[r])
            {
                if (fin[l] == sec)
                {
                    cnt--;
                    l++;
                }
                else if (fin[r] == sec)
                {
                    cnt--;
                    r--;
                }
                else
                {
                    // cout << "h1" << endl;
                    // cout << l << " " << r << endl;
                    ans = false;
                    break;
                }
            }
            if (fin[l] == fin[r])
            {
                l++;
                r--;
            }

            if (cnt < 0)
            {
                ans = false;
                // cout << "h2" << endl;
                break;
            }
        }
        if (ans == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
