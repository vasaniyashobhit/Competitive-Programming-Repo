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
        vector<int> v(n);
        for (int &it : v)
            cin >> it;
        int ans = 1;
        bool dec = false;
        int decint;
        for (int i = 1; i < n; i++)
        {
            if (v[i] < v[i - 1])
            {
                dec = true;
                decint = v[i];
            }
            if (dec == true && v[i] > decint)
            {
                ans++;
                dec = false;
                // cout << v[i] << " ";
            }
        }
        // cout << endl;
        cout << ans << endl;
    }

    return 0;
}