#include <iostream>
#include <vector>
using namespace std;

int ask(int ind)
{
    vector<int> v(ind);
    int count = 0;
    cout << "? " << 1 << " " << ind << endl;
    for (int i = 0; i < ind; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < ind; i++)
    {
        if (v[i] <= ind)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int l = 1, r = n;
        int ans = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int count = ask(mid);
            if (count % 2 != 0)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << "! " << ans << endl;
    }

    return 0;
}