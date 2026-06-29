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
        vector<long long> a(n);
        for (long long &it : a)
        {
            cin >> it;
        }
        vector<long long> ans;
        ans.push_back(a[0]);
        long long i = 0;
        while (i < n)
        {
            long long x = a[i];
            long long j = i + 1;
            while (j < n && a[j] <= a[i] + 1)
            {
                j++;
            }
            if (j == n)
                break;
            ans.push_back(a[j]);
            if (i == n - 1)
                break;
            i = j;
        }
        // for (auto it : ans)
        //     cout << it << " ";
        // cout << endl;
        cout << ans.size() << endl;
    }
    return 0;
}
