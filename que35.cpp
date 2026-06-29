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
        long long n;
        cin >> n;
        cout << 1 << " ";
        for (long long i = n; i >= 2; i--)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}