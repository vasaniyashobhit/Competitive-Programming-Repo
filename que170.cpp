#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, b, s;
        cin >> n >> k >> b >> s;
        if ((s < b * k) || (s > (b * k + (k - 1) * n)))
            cout << -1 << endl;
        else
        {
            // cout << b * k << " ";
            s -= b * k;
            for (long long i = 1; i < n; i++)
            {
                if (s >= (k - 1))
                {
                    cout << (k - 1) << " ";
                    s -= (k - 1);
                }
                else
                {
                    cout << s << " ";
                    s = 0;
                }
            }
            if (s > 0)
                cout << ((b * k) + s) << endl;
            else
                cout << (b * k) << endl;
        }
    }

    return 0;
}