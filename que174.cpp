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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> pref(n, 0);
        if (s[0] == 'B')
            pref[0] = 1;
        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1];
            if (s[i] == 'B')
                pref[i]++;
        }
        int ans = k - pref[k - 1];
        for (int i = k; i < n; i++)
        {
            ans = min(ans, k - (pref[i] - pref[i - k]));
        }
        cout << ans << endl;
    }

    return 0;
}