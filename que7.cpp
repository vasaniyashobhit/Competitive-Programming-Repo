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
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &it : v)
            cin >> it;

        int n1, n2;
        if (n % 2 == 0)
        {
            n1 = n2 = n / 2;
        }
        else
        {
            n1 = (n / 2) + 1;
            n2 = n / 2;
        }
        vector<int> even(n1, -1);
        vector<int> odd(n2, -1);
        int k1 = 0, k2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                even[k1] = v[i];
                k1++;
            }
            else
            {
                odd[k2] = v[i];
                k2++;
            }
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        k1 = 0;
        k2 = 0;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                cout << even[k1] << " ";
                k1++;
            }
            else
            {
                cout << odd[k2] << " ";
                k2++;
            }
        }
        cout << endl;
    }

    return 0;
}