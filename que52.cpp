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
        int k = 2 * n - 3;
        cout << k << endl;
        for (int i = 2; i <= n; i++)
        {
            cout << i << " " << 1 << " " << i << endl;
        }
        for (int i = 1; i < n - 1; i++)
        {
            cout << i << " " << (i + 1) << " " << n << endl;
        }
    }

    return 0;
}