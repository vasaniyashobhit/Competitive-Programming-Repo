#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long allmin = 1e9 + 1, allsecmini = 1e9 + 1;
        long long ans = 0;
        while (n--)
        {
            long long m;
            cin >> m;
            vector<long long> a(m, 0);
            for (long long &it : a)
                cin >> it;
            long long mini = 1e9 + 1, secmini = 1e9 + 1;
            for (int i = 0; i < m; i++)
            {
                if (a[i] < allmin)
                    allmin = a[i];
                if (a[i] <= mini)
                {
                    secmini = mini;
                    mini = a[i];
                }
                else if (a[i] <= secmini)
                    secmini = a[i];
            }
            if (secmini < allsecmini)
                allsecmini = secmini;
            ans += secmini;
        }
        ans -= allsecmini;
        ans += allmin;
        cout << ans << endl;
    }

    return 0;
}