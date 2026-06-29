#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int w, h, a, b;
        cin >> w >> h >> a >> b;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        bool ans = true;
        int xgap = abs(x2 - (x1 + a));
        int ygap = abs(y2 - (y1 + b));
        // cout << xgap << " " << ygap << endl;
        if (w == 1 && h == 1)
        {
            cout << "YES" << endl;
            continue;
        }
        if (w == 1)
        {
            if ((ygap < b && (ygap > 0)))
            {
                cout << "NO" << endl;
            }
            else
                cout << "YES" << endl;
            continue;
        }
        if (h == 1)
        {
            if ((xgap < a) && (xgap > 0))
            {
                cout << "NO" << endl;
            }
            else
                cout << "YES" << endl;
            continue;
        }
        ans = true;

        if ((xgap % a != 0) && (ygap % b != 0))
        {
            ans = false;
        }

        if (ans == true)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}