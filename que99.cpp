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
        if (n == 1)
        {
            cout << "NO" << endl;
            continue;
        }

        bool ans = false;
        int k = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                ans = true;
                k = i;
                break;
            }
        }
        if (ans == false)
            cout << "NO" << endl;
        else
        {
            cout << "Yes" << endl;
            cout << 2 << endl;
            cout << a[k - 1] << " " << a[k] << endl;
        }
    }

    return 0;
}