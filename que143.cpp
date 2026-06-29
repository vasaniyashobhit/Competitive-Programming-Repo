#include <iostream>
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
        int op, ind = -1;
        char gr = 'a', fn;
        for (int i = 0; i < n; i++)
        {
            if ((s[i] - 'a') > k)
            {
                ind = i;
                fn = s[i];
                break;
            }
            if (s[i] > gr)
                gr = s[i];
        }
        if (ind == -1)
        {
            string ans(n, 'a');
            cout << ans << endl;
            continue;
        }
        op = gr - 'a';
        char sm = fn - (k - op);
        for (int i = 0; i < n; i++)
        {
            if (s[i] <= gr)
                s[i] = 'a';
            if (s[i] > sm && s[i] <= fn)
            {
                s[i] = sm;
            }
        }
        cout << s << endl;
    }

    return 0;
}