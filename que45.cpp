#include <iostream>
#include <vector>
using namespace std;

bool check(vector<pair<int, int>> a, int sum, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if ((a[i].first >= (sum - count - 1)) && (a[i].second >= count))
        {
            count++;
        }
        if (count >= sum)
        {
            break;
        }
    }
    if (count < sum)
    {
        return false;
    }
    else
        return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n, {0, 0});
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            cin >> a[i].second;
        }

        int l = 1, r = n;
        int ans = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (check(a, mid, n))
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