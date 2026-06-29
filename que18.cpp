#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        long long a = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                a++;
            }
            else
            {
                b++;
            }
        }

        long long x = n - (2 * k);
        long long ans = true;

        if (a >= x / 2)
        {
            a -= x / 2;
        }
        else
        {
            ans = false;
        }

        if (b >= x / 2)
        {
            b -= x / 2;
        }
        else
        {
            ans = false;
        }

        if (ans == false)
        {
            cout << "NO" << endl;
            continue;
        }
        if (a % 2 == 0 && b % 2 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}