#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &it : v)
        {
            cin >> it;
        }

        sort(v.begin(), v.end());
        int lodd = -1;
        int rodd = -1;
        int leven = -1;
        int reven = -1;
        bool even = false;
        bool odd = false;
        for (int i = 0; i < n; i++)
        {
            if (v[i] % 2 == 0 && even == false)
            {
                leven = i;
                even = true;
                // cout << leven << " ";
            }
            if (v[i] % 2 != 0 && odd == false)
            {
                lodd = i;
                odd = true;
                // cout << lodd << " ";
            }
        }
        bool odd1 = false;
        bool even1 = false;
        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i] % 2 == 0 && even1 == false)
            {
                even1 = true;
                reven = i;
                // cout << reven << " ";
            }
            if (v[i] % 2 != 0 && odd1 == false)
            {
                odd1 = true;
                rodd = i;
                // cout << rodd << " ";
            }
        }
        // cout << endl;
        //  cout << leven << " " << reven << " " << rodd << " " << lodd << endl;
        if (lodd == -1)
        {
            cout << 0 << endl;
        }
        else if (leven == -1)
        {
            cout << 0 << endl;
        }
        else
        {
            int ans = min(n - (reven - leven + 1), n - (rodd - lodd + 1));
            cout << ans << endl;
        }
    }

    return 0;
}