#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, n;
        cin >> x >> n;
        long long nn = n - (n % 4);
        nn++;
        while (nn <= n)
        {
            if (x % 2 == 0)
            {
                x -= nn;
            }
            else
            {
                x += nn;
            }
            nn++;
        }
        cout << x << endl;
    }

    return 0;
}