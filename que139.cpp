#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << 0 << " " << 0 << endl;
        }
        else
        {
            long long diff = abs(a - b);
            cout << diff << " " << min(a % diff, diff - (a % diff)) << endl;
        }
    }

    return 0;
}