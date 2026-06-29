#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        string s;
        cin >> s;
        string ss(n, '0');
        long long ans = 0;
        for (long long i = 1; i <= n; i++)
        {
            // cout << "h3" << " ";
            long long j = i;
            while (j <= n && s[j - 1] == '0')
            {
                // cout << "h" << " ";
                if (ss[j - 1] == '0')
                {
                    // cout << i << " ";
                    ans += i;
                    ss[j - 1] = '1';
                }
                j += i;
            }
        }
        // cout << endl;
        cout << ans << endl;
    }

    return 0;
}