#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> a(n, vector<int>(3));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> a[i][j];
            }
        }
        sort(a.begin(), a.end());

        int c = k;
        for (int i = 0; i < n; i++)
        {
            if (c < a[i][0])
            {
                break;
            }
            else if (c > a[i][1])
            {
                continue;
            }
            else
            {
                c = max(c, a[i][2]);
            }
        }
        cout << c << endl;
    }

    return 0;
}