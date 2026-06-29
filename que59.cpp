#include <iostream>
#include <vector>
using namespace std;

bool check(int n, vector<int> a, vector<int> b, vector<pair<int, int>> mini, vector<int> lr, int mid, vector<int> mb)
{
    if (mid == 0)
    {
        return true;
    }
    else if (mid == n)
    {
        if ((mini[n - 1].first > b[0]) && (mini[n - 1].second > b[0]))
        {
            return true;
        }
        else
            return false;
    }
    if (n == 1)
    {
        if (a[0] > b[0])
        {
            return true;
        }
        else
            return false;
    }
    if (lr[mid] > mini[mid - 1].first && mid < n)
    {
        mini[mid - 1].first = lr[mid];
        if (mid == 1)
        {
            mini[mid - 1].second = lr[mid];
        }
    }
    int ch = mb[n - mid];
    // cout << mini[mid - 1].first << " " << mini[mid - 1].second << " " << ch << endl;
    if (mini[mid - 1].first > ch && mini[mid - 1].second > ch)
    {
        return true;
    }
    else
        return false;
}

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
        vector<int> b(n);
        for (int &it : b)
            cin >> it;

        if (n == 1)
        {
            if (a[0] > b[0])
            {
                cout << 1 << endl;
            }
            else
                cout << 0 << endl;
            continue;
        }

        vector<pair<int, int>> mini(n, {a[0], a[0]});
        pair<int, int> cal{a[0], a[0]};
        mini[0].first = a[0];
        mini[0].second = a[0];
        if (a[0] > a[1])
        {
            cal.first = a[1];
            cal.second = a[0];
            mini[1].first = a[1];
            mini[1].second = a[0];
        }
        else
        {
            cal.first = a[0];
            cal.second = a[1];
            mini[1].first = a[0];
            mini[1].second = a[1];
        }
        for (int i = 2; i < n; i++)
        {
            if (a[i] < cal.first)
            {
                cal.second = cal.first;
                cal.first = a[i];
            }
            else if (a[i] < cal.second)
            {
                cal.second = a[i];
            }

            mini[i].first = cal.first;
            mini[i].second = cal.second;
        }

        vector<int> lr(n, 0);
        int larg = a[n - 1];
        lr[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] > larg)
            {
                larg = a[i];
            }
            lr[i] = larg;
        }

        vector<int> mb(n);
        mb[0] = b[0];
        int mmbb = b[0];
        for (int i = 1; i < n; i++)
        {
            if (b[i] < mmbb)
            {
                mmbb = b[i];
            }
            mb[i] = mmbb;
        }

        int l = 0, r = n;
        int ans = 0;
        // cout << check(n, a, b, mini, lr, 1, mb) << endl;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (check(n, a, b, mini, lr, mid, mb))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}