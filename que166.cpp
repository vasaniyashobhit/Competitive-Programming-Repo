#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for (int &it : a)
            cin >> it;
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            if (a[i] == 0)
                cnt0++;
            else if (a[i] == 1)
                cnt1++;
            else
                cnt2++;
        }

        if (sum > s)
        {
            for (auto it : a)
                cout << it << " ";
            cout << endl;
        }
        else if (sum == s)
        {
            cout << -1 << endl;
        }
        else
        {
            if (sum + 1 == s)
            {
                for (int i = 0; i < cnt0; i++)
                {
                    cout << 0 << " ";
                }
                for (int i = 0; i < cnt2; i++)
                {
                    cout << 2 << " ";
                }
                for (int i = 0; i < cnt1; i++)
                {
                    cout << 1 << " ";
                }
                cout << endl;
            }
            else
                cout << -1 << endl;
        }
    }

    return 0;
}