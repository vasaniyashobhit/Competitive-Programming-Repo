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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a(26, 0);
        for (int i = 0; i < n; i++)
        {
            a[s[i] - 'a']++;
        }

        int ans = false;
        for (int i = 0; i < 26; i++)
        {
            if (a[i] > 2)
            {
                ans = true;
                break;
            }
            if (a[i] == 2)
            {
                char c = i + 'a';
                if ((s[0] != c) || (s[n - 1] != c))
                {
                    ans = true;
                    break;
                }
            }
        }
        if (ans == false)
        {
            cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;
    }

    return 0;
}