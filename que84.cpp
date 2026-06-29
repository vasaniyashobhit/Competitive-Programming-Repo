#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (long long &it : a)
            cin >> it;

        bool k = true;
        bool p = false;
        if ((abs(a[0] - a[1]) <= 1) || (abs(a[n - 2] - a[n - 1]) <= 1))
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (abs(a[i] - a[i + 1]) <= 1)
            {
                k = false;
                p = true;
                break;
            }
            if (a[i] >= a[i - 1] && a[i] >= a[i + 1])
            {
                k = false;
            }
            if (a[i] <= a[i - 1] && a[i] <= a[i + 1])
            {
                k = false;
            }
        }
        if (p == true)
        {
            cout << 0 << endl;
        }
        else if (k == true)
        {
            cout << -1 << endl;
        }
        else
            cout << 1 << endl;
    }

    return 0;
}