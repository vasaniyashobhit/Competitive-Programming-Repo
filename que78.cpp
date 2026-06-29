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
        int l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

        if ((l1 == l2 + l3) && (b2 == b3) && (l1 == b1 + b2))
        {
            cout << "YES" << endl;
            continue;
        }
        else if ((b1 == b2 + b3) && (l2 == l3) && (b1 == l1 + l2))
        {
            cout << "YES" << endl;
            continue;
        }
        else if ((l1 == l2 && l2 == l3) && (b1 + b2 + b3 == l1))
        {
            cout << "YES" << endl;
            continue;
        }
        else if ((b1 == b2) && (b2 == b3) && (l1 + l2 + l3 == b1))
        {
            cout << "YES" << endl;
            continue;
        }
        else
        {
            cout << "NO" << endl;
            continue;
        }
    }

    return 0;
}