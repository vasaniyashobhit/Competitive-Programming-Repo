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
        bool ans = false;
        int ind = -1;
        for (int i = 1; i < 2 * n - 1; i += 2)
        {
            cout << "? " << i << " " << i + 1 << endl;
            int x;
            cin >> x;
            if (x == 1)
            {
                ans = true;
                ind = i;
                break;
            }
        }

        if (ans == true)
        {
            cout << "! " << ind << endl;
        }
        else
        {
            cout << "? " << 2 * n - 1 << " " << 2 * n - 2 << endl;
            int x;
            cin >> x;
            if (x == 1)
            {
                cout << "! " << 2 * n - 1 << endl;
            }
            else
            {
                cout << "? " << 2 * n - 1 << " " << 2 * n - 3 << endl;
                int y;
                cin >> y;
                if (y == 1)
                {
                    cout << "! " << 2 * n - 1 << endl;
                }
                else
                {
                    cout << "! " << 2 * n << endl;
                }
            }
        }
    }

    return 0;
}