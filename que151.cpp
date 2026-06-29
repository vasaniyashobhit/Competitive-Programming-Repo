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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &it : a)
            cin >> it;
        string ans = "L";
        int l = 1, r = n - 1;
        int num = a[0];
        while (l <= r)
        {
            if (l == r)
            {
                ans += "L";
                break;
            }
            if (a[l] > num && a[r] > num)
            {
                if (a[l] > a[r])
                {
                    ans += "LR";
                    num = a[r];
                }
                else
                {
                    ans += "RL";
                    num = a[l];
                }
            }
            else
            {
                if (a[l] < a[r])
                {
                    ans += "LR";
                    num = a[r];
                }
                else
                {
                    ans += "RL";
                    num = a[l];
                }
            }
            l++, r--;
        }
        // cout << endl;

        cout << ans << endl;
    }

    return 0;
}