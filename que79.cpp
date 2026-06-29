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
        long long n, s;
        cin >> n >> s;
        vector<vector<long long>> a(n, vector<long long>(4)); //  [ {{dx,dy},{x,y}}]
        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < 4; j++)
            {
                cin >> a[i][j];
            }
        }
        long long ans = 0;
        for (long long i = 0; i < n; i++)
        {
            if (a[i][2] == a[i][3])
            {
                if ((s % 2 == 0) && (a[i][2] == s / 2))
                {
                    ans++;
                }
                else if (a[i][0] == a[i][1])
                {
                    ans++;
                }
            }
            else if (a[i][2] + a[i][3] == s)
            {
                if ((s % 2 == 0) && (a[i][2] == s / 2))
                {
                    ans++;
                }
                else if ((a[i][0]) * (-1) == a[i][1])
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}