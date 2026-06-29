#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(s[i]) == mp.end())
        {
            mp[s[i]] = 1;
        }
    }
    int k = mp.size();
    // cout << k << endl;

    int l = 0, r = 0;
    int ans = n;
    map<char, int> seg;
    seg[s[0]] = 1;
    while (l < n && r < n)
    {
        while (seg.size() < k)
        {
            r++;
            if (seg.find(s[r]) == seg.end())
            {
                seg[s[r]] = 1;
            }
            else
            {
                seg[s[r]]++;
            }
        }
        int len = r - l + 1;
        ans = min(ans, len);
        seg[s[l]]--;
        if (seg[s[l]] == 0)
        {
            seg.erase(s[l]);
        }
        l++;
    }
    cout << ans << endl;

    return 0;
}