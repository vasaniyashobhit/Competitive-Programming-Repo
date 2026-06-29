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
        string s;
        cin >> s;

        for (int i = 0; i < n - k; i++)
        {
            if (s[i] == '1')
            {
                s[i] = '0';
                if(s[i+k]=='1') s[i+k] ='0';
                else s[i+k] = '1'; 
            }
        }

        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                ans = false;
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}