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
        cin >> n;
        vector<int> a(n);
        for (int &it : a)
            cin >> it;
        vector<int> ans;

        int l = 0, r = 0;
        bool k = true;
        while (r < n)
        {
            while (r < n && a[l] == a[r])
                r++;
            if (r == l + 1)
            {
                k = false;
                break;
            }
            ans.push_back(r);
            while (l < r - 1)
            {
                ans.push_back((l + 1));
                l++;
            }
            l = r;
        }
        if (k == true)
        {
            for (auto it : ans)
                cout << it << " ";
            cout << endl;
        }
        else
            cout << -1 << endl;
    }

    return 0;
}