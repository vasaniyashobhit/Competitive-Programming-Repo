#include <iostream>
#include <map>
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
        string s;
        cin >> s;
        vector<int> pref(n, 0);
        map<char, int> mp1;
        for (int i = 0; i < n; i++)
        {
            mp1[s[i]] = 1;
            pref[i] = mp1.size();
        }
        vector<int> suff(n, 0);
        map<char, int> mp2;
        for (int i = n - 1; i >= 0; i--)
        {
            suff[i] = mp2.size();
            mp2[s[i]] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, pref[i] + suff[i]);
        }
        cout << ans << endl;
    }

    return 0;
}