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
        vector<int> a(n, 0);
        for (int &it : a)
            cin >> it;
        bool ans = false;
        for (int i = 1; i < n - 1; i++)
        {
            if ((a[i] > a[i - 1]) && (a[i] > a[i + 1]))
            {
                ans = true;
                cout << "YES" << endl;
                cout << (i) << " " << i + 1 << " " << i + 2 << endl;
                break;
            }
        }
        if (ans == false)
            cout << "NO" << endl;
    }

    return 0;
}