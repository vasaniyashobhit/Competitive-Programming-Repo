#include <iostream>
#include <vector>
#include <set>
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

        vector<int> v = {0, 0, 0, 1, 2, 2, 3, 5};
        map<int, int> mp;
        for (int i = 0; i < 8; i++)
        {
            if (mp.find(v[i]) == mp.end())
            {
                mp[v[i]] = 1;
            }
            else
            {
                mp[v[i]]++;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(a[i]) != mp.end())
            {
                mp[a[i]]--;
                if (mp[a[i]] == 0)
                {
                    mp.erase(a[i]);
                }
            }
            if (mp.size() == 0)
            {
                ans = i + 1;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}