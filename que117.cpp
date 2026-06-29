#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &it : a)
            cin >> it;

        int ans = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                count++;
                if (count == k)
                {
                    ans++;
                    i++;
                    count = 0;
                }
            }
            else
            {
                count = 0;
            }
        }
        cout << ans << endl;
    }

    return 0;
}