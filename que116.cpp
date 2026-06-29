#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 9;
        while (n > 0)
        {
            int i = n % 10;
            ans = min(ans, i);
            n /= 10;
        }
        cout << ans << endl;
    }

    return 0;
}