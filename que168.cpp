#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        char c;
        cin >> n >> c;
        string s;
        cin >> s;
        s += s;
        int nn = 2 * n;
        int ans = 0;
        vector<int> gg;
        for (int i = 0; i < nn; i++)
        {
            if (s[i] == 'g')
                gg.push_back(i);
        }

        for (int i = 0; i < n; i++)
        {
            if (s[i] == c)
            {
                int ind = *(lower_bound(gg.begin(), gg.end(), i));
                ans = max(ans, ind - i);
            }
        }
        cout << ans << endl;
    }

    return 0;
}