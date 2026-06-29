#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n, {0, 0});
        for (pair<int, int> &it : a)
        {
            cin >> it.first;
        }
        for (pair<int, int> &it : a)
        {
            cin >> it.second;
        }

        if (a[n - 1].first == a[n - 1].second)
        {
            cout << n << endl;
            continue;
        }
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        if (a[n - 2].first == a[n - 2].second)
        {
            cout << (n - 1) << endl;
            continue;
        }
        if ((a[n - 2].first == a[n - 1].first) || (a[n - 2].second == a[n - 1].second))
        {
            cout << (n - 1) << endl;
            continue;
        }
        if (n == 2)
        {
            cout << 0 << endl;
            continue;
        }

        int ans = 0;
        set<int> st;
        for (int i = n - 3; i >= 0; i--)
        {
            st.insert(a[i + 2].first);
            st.insert(a[i + 2].second);

            if (a[i].first == a[i].second)
            {
                ans = i + 1;
                break;
            }
            if ((a[i].first == a[i + 1].first) || (a[i].second == a[i + 1].second))
            {
                ans = i + 1;
                break;
            }
            if ((st.find(a[i].first) != st.end()) || (st.find(a[i].second) != st.end()))
            {
                ans = i + 1;
                break;
            }
        }
        cout << ans << endl;
    }
}