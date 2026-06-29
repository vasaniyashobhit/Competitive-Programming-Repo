#include <iostream>
#include <vector>
#include <map>
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
        vector<int> b(n);
        for (int &it : b)
            cin >> it;

        map<int, int> mp;
        int l = 0, r = 0, maxlen = 0;
        while (r < n)
        {
            int num = a[l];
            while (r < n && a[l] == a[r])
                r++;
            maxlen = max(maxlen, r - l);
            if (mp.find(num) != mp.end())
            {
                mp[num] = max(r - l, mp[num]);
            }
            else
                mp[num] = r - l;
            l = r;
        }
        l = 0;
        r = 0;
        while (r < n)
        {
            int num = b[l];
            int prev = mp.find(num) != mp.end() ? mp[num] : 0;
            while (r < n && b[l] == b[r])
                r++;
            int len = r - l + prev;
            maxlen = max(len, maxlen);
            l = r;
        }
        cout << maxlen << endl;
    }

    return 0;
}