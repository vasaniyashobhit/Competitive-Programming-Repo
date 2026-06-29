#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r, b;
        cin >> n >> r >> b;
        int cnt = r / (b + 1);
        int rem = r - cnt * (b + 1);
        string one(cnt, 'R');
        string ans = "";
        while (n > 0)
        {
            ans += one;
            n -= cnt;
            if (rem > 0)
            {
                ans += "R";
                n--;
                rem--;
            }
            if (n > 0)
                ans += "B";
            n--;
        }
        cout << ans << endl;
    }

    return 0;
}