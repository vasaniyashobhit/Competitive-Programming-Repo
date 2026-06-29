#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r;
        cin >> l >> r;
        string ll = "", rr = "";
        while (l > 0 && r > 0)
        {
            int i = l % 10;
            int j = r % 10;
            ll = to_string(i) + ll;
            rr = to_string(j) + rr;
            l /= 10;
            r /= 10;
        }
        int ans = 0;
        int i = 0;
        while (i < ll.size() && ll[i] == rr[i])
        {
            ans += 2;
            i++;
        }

        while (i < ll.size() && (ll[i] == '9' && rr[i] == 0))
        {
            ans += 1;
            i++;
        }
        cout << ans << endl;
    }

    return 0;
}