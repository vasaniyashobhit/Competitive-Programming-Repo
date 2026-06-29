#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        string ans = "";
        sort(s.begin(), s.end());
        for (int i = 0; i < n; i += 2)
            ans += s[i];
        if (n % 2 == 0)
        {
            for (int i = n - 1; i >= 0; i -= 2)
                ans += s[i];
        }
        else
        {
            for (int i = n - 2; i >= 0; i -= 2)
                ans += s[i];
        }
        cout << ans << endl;
    }

    return 0;
}