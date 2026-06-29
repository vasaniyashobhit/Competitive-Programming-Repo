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
            cin >> it;
        long long sm = a[0];
        bool ans = true;
        for (int i = 1; i < n; i++)
        {
            if (a[i] > (2 * sm) - 1 && a[i] > sm)
            {
                ans = false;
                break;
            }
            if (a[i] < sm)
                sm = a[i];
        }
        if (ans == false)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}