#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s1(k, '1');
        string s2(n - k, '0');
        s1 += s2;
        cout << s1 << endl;
    }

    return 0;
}