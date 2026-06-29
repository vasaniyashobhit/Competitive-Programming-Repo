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
        vector<int> a(n);
        for (int &it : a)
            cin >> it;
        int num = -1;
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == -1)
                continue;
            if (num == -1)
            {
                num = a[i];
            }
            if (num != a[i] || num == 0 || a[i] == 0)
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