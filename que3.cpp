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
        vector<int> a(n);
        for (auto &it : a)
            cin >> it;

        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        else if (n == 2)
        {
            if (a[0] == a[1])
            {
                cout << 1 << endl;
                continue;
            }
            else
            {
                cout << 2 << endl;
                continue;
            }
        }

        for (int i = 0; i < n - 2; i++)
        {
            if (a[i] <= a[i + 1] && a[i + 1] <= a[i + 2])
            {
                a[i + 1] = a[i];
                a[i] = -1;
            }
            else if (a[i] >= a[i + 1] && a[i + 1] >= a[i + 2])
            {
                a[i + 1] = a[i];
                a[i] = -1;
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != -1)
            {
                count++;
            }
        }

        if (count == 2 && a[n - 2] == a[n - 1])
        {
            cout << 1 << endl;
            continue;
        }
        cout << count << endl;
    }

    return 0;
}