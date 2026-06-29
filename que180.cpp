#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int ans = 100;
        for (int i = 0; i <= 32; i++)
        {
            int count = i;
            int bb = b + i;
            if (b == 1 && i == 0)
                continue;
            int n = a;
            while (n > 0)
            {
                count++;
                n /= bb;
            }
            ans = min(ans, count);
        }
        cout << ans << endl;
    }

    return 0;
}