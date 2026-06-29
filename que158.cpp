#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, c, d;
        cin >> n >> c >> d;
        vector<long long> a(n);
        for (long long &it : a)
            cin >> it;

        sort(a.begin(), a.end());
        vector<long long> st;
        st.push_back(a[0]);
        for (int i = 1; i < n; i++)
        {
            if (a[i] != a[i - 1])
                st.push_back(a[i]);
        }
        long long s = st.size();
        long long ans = c * (n - s);
        long long mincost = __LONG_LONG_MAX__;
        for (int i = 0; i < s; i++)
        {
            int p = i + 1;
            long long cost = c * (s - p) + d * (st[i] - p);
            mincost = min(cost, mincost);
        }
        mincost = mincost + ans;
        long long cost = c * (n) + d;
        mincost = min(mincost, cost);
        cout << mincost << endl;
    }

    return 0;
}