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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (auto &it : a)
            cin >> it;
        bool used = false;
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                used = true;
            }
            if (used == true && x > 0)
            {
                x--;
                continue;
            }
            if (x <= 0 && a[i] == 1)
            {
                ans = false;
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