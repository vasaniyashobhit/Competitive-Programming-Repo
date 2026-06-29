#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, j, k;
        cin >> n >> j >> k;
        vector<long long> a(n);
        for (long long &it : a)
            cin >> it;

        if (k == 1)
        {
            bool ans = true;
            for (int i = 0; i < n; i++)
            {
                if (a[i] > a[j - 1])
                {
                    ans = false;
                    break;
                }
            }
            if (ans == true)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}