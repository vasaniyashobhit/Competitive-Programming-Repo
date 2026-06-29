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
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        int min1 = 0, min11 = 0, min2 = 0, min22 = 0;
        for (int i = x; i < n; i++)
        {
            if (s[i] == '#')
            {
                min11 = n - i;
                break;
            }
        }
        for (int i = x - 2; i >= 0; i--)
        {
            if (s[i] == '#')
            {
                min22 = i + 1;
                break;
            }
        }
        min1 = x - 1;
        min2 = n - x;
        int ans1 = min(min1, min11);
        int ans2 = min(min2, min22);
        int fans = max(ans1, ans2);
        cout << (fans + 1) << endl;
    }

    return 0;
}