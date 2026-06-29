#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string even = "";
        string odd = "";
        string ans = "";
        for (auto c : s)
        {
            if (c % 2 == 0)
                even += c;
            else
                odd += c;
        }

        int p1 = 0, p2 = 0;
        while (p1 < even.size() && p2 < odd.size())
        {
            if ((even[p1] - '0') < (odd[p2] - '0'))
                ans += even[p1++];
            else
                ans += odd[p2++];
        }
        while (p1 < even.size())
            ans += even[p1++];
        while (p2 < odd.size())
            ans += odd[p2++];
        cout << ans << endl;
    }

    return 0;
}