#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &it : a)
        cin >> it;
    int m;
    cin >> m;
    vector<int> q(m);
    for (int &it : q)
        cin >> it;

    vector<int> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }

    for (int i = 0; i < m; i++)
    {
        int l = 0, r = n - 1;
        int ans;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (pref[mid] < q[i])
            {
                l = mid + 1;
            }
            else
            {
                // cout << ans << " ";
                ans = mid;
                r = mid - 1;
            }
        }
        // cout << endl;
        cout << (ans + 1) << endl;
    }

    return 0;
}