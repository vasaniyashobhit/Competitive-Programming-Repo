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
        vector<int> a(n);
        for (int &it : a)
            cin >> it;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            if (a[i] == 0)
                sum++;
        }
        cout << sum << endl;
    }

    return 0;
}